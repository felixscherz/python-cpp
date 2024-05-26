#include <Python.h>


/* functions always return a PyObject pointer and take a reference to python via self */
static PyObject *_hello_world(PyObject *self) {
  PyObject *text = PyUnicode_FromString("Hello World!");
  return text;
}


/* methods can be marked as taking no arguments METH_NOARGS, or METH_VARARGS */
/* the function is exposed as `hello_world` to the module namespace */
static PyMethodDef methods[] = {
    {"hello_world", (PyCFunction)_hello_world, METH_NOARGS},
    {NULL, NULL} // sentinel value that marks the end of the methods array
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT, "_hello", NULL, -1, methods
};

PyMODINIT_FUNC PyInit__hello(void) {
    return PyModule_Create(&module);
}
