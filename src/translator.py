from builder import Builder

from dataclasses import dataclass
from typing import Callable


@dataclass
class Translator:
    include_list: list[str]
    setup_action_list: list[Callable]
    gate_action_dict: dict[str, Callable]

    @staticmethod
    def new():
        return Translator([], [], {})

    def add_include(self, name):
        self.include_list.append(name)

    def add_setup_action(self, setup_f):
        self.setup_action_list.append(setup_f)

    def add_constexpr_definition(self, name, expr_type, value):
        self.setup_action_list.append(lambda builder: builder.append(f'constexpr {expr_type} {name} = {value};\n\n'))

    def add_matrix_definition(self, name, size, real, imag):
        def define_matrix(builder):
            builder.append(f'constexpr ComplexMatrix{size} {name} = {{ .real={real}, .imag={imag} }};\n\n')

        self.setup_action_list.append(define_matrix)

    def add_function_definition(self, header, *lines):
        def define_function(builder):
            builder.append(f'{header} {{\n')
            inner_builder = builder.inner()
            for line in lines:
                inner_builder.append(f'{line}\n')
            builder.append('}\n\n')

        self.setup_action_list.append(define_function)

    def add_gate_action(self, name, action_f):
        self.gate_action_dict[name] = action_f

    def translate(self, file_name):
        root_builder = Builder.new()
        inner_builder = root_builder.inner()

        root_builder.append('#include "QuEST.h"\n\n')

        for include in self.include_list:
            root_builder.append(f'#include {include}\n')
        root_builder.newline()

        lines: list[str]
        with open(file_name) as file:
            lines = file.readlines()

        qubits = int(lines[0])

        for action in self.setup_action_list:
            action(root_builder)

        root_builder.append('void run_circuit(Qureg const& reg) {\n')

        for i, line in enumerate(lines[1:]):
            line_number = i + 2
            split = line.split()
            if len(split) > 2:
                gate_name = split[1]
                if gate_name in self.gate_action_dict:
                    self.gate_action_dict[gate_name](inner_builder, *split[2:])
                else:
                    raise KeyError(f'Line {line_number}: gate action for \'{gate_name}\' not defined!')

        root_builder.append('}\n\n')

        root_builder.append('int main(int argc, char** argv) {\n')
        inner_builder.append('auto env = createQuESTEnv();\n\n')
        inner_builder.append(f'auto reg_size = {qubits};\n')
        inner_builder.append(f'auto reg = createQureg(reg_size, env);\n\n')
        inner_builder.append('run_circuit(reg);\n\n')
        inner_builder.append('// Analysis code here!\n\n')
        inner_builder.append('destroyQureg(reg, env);\n')
        inner_builder.append('destroyQuESTEnv(env);\n\n')
        inner_builder.append('return 0;\n')
        root_builder.append('}\n')

        return str(root_builder)
