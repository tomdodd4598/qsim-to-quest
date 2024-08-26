from builder import Builder
from translator import Translator


def main():
    Builder.set_indentation(4 * ' ')

    translator = Translator.new()

    translator.add_include('<cmath>')

    translator.add_constexpr_definition('INV_SQRT_2', 'qreal', '0.707106781186547524400844362104849039')

    translator.add_matrix_definition('SQRT_X', 2, '{{INV_SQRT_2, 0.0}, {0.0, INV_SQRT_2}}', '{{0.0, -INV_SQRT_2}, {-INV_SQRT_2, 0.0}}')
    translator.add_matrix_definition('SQRT_Y', 2, '{{INV_SQRT_2, -INV_SQRT_2}, {INV_SQRT_2, INV_SQRT_2}}', '{{0.0, 0.0}, {0.0, 0.0}}')
    translator.add_matrix_definition('SQRT_W', 2, '{{INV_SQRT_2, -0.5}, {0.5, INV_SQRT_2}}', '{{0.0, -0.5}, {-0.5, 0.0}}')

    translator.add_function_definition(
        'auto sycamore_swap(qreal theta, qreal phi)',
        'auto cos_t = cos(theta), sin_t = sin(theta);',
        'return ComplexMatrix4 { .real={{1.0, 0.0, 0.0, 0.0}, {0.0, cos_t, 0.0, 0.0}, {0.0, 0.0, cos_t, 0.0}, {0.0, 0.0, 0.0, cos(phi)}}, .imag={{0.0, 0.0, 0.0, 0.0}, {0.0, 0.0, -sin_t, 0.0}, {0.0, -sin_t, 0.0, 0.0}, {0.0, 0.0, 0.0, -sin(phi)}} };'
    )

    def define_unitary_action(key, matrix):
        translator.add_gate_action(key, lambda builder, q: builder.append(f'unitary(reg, {q}, {matrix});\n'))

    define_unitary_action('x_1_2', 'SQRT_X')
    define_unitary_action('y_1_2', 'SQRT_Y')
    define_unitary_action('hz_1_2', 'SQRT_W')

    translator.add_gate_action('rz', lambda builder, q, angle: builder.append(f'rotateZ(reg, {q}, {angle});\n'))
    translator.add_gate_action('fs', lambda builder, q1, q2, theta, phi: builder.append(f'twoQubitUnitary(reg, {q1}, {q2}, sycamore_swap({theta}, {phi}));\n'))

    with open('../output/circuit_n12_m14_s9_e0_pEFGH.cpp', 'w') as file:
        file.write(translator.translate('../input/circuit_n12_m14_s9_e0_pEFGH.qsim'))


if __name__ == '__main__':
    main()
