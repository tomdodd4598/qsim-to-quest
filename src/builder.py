from dataclasses import dataclass


_indentation = '\t'


@dataclass
class Builder:
    internal: list
    indentation: str

    @staticmethod
    def new():
        return Builder([], '')

    @staticmethod
    def set_indentation(string):
        global _indentation
        _indentation = string

    def inner(self):
        return Builder(self.internal, self.indentation + _indentation)

    def append(self, obj):
        self.internal.append(self.indentation)
        self.internal.append(obj)

    def newline(self):
        self.internal.append('\n')

    def __str__(self):
        return ''.join(self.internal)

    def __repr__(self):
        return str(self)
