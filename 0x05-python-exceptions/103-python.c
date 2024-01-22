#include <Python.h>

void print_python_list(PyObject *p)
{
    PyListObject *list;
    PyVarObject *varobj;
    Py_ssize_t size, i;

    printf("[*] Python list info\n");

    if (!PyList_Check(p))
    {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    list = (PyListObject *)p;
    varobj = (PyVarObject *)p;
    size = varobj->ob_size;

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", varobj->ob_alloc);

    for (i = 0; i < size; ++i)
    {
        printf("Element %zd: %s\n", i, Py_TYPE(list->ob_item[i])->tp_name);
    }
}

void print_python_bytes(PyObject *p)
{
    PyBytesObject *bytes;
    PyVarObject *varobj;
    Py_ssize_t size, i;

    printf("[.] bytes object info\n");

    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    bytes = (PyBytesObject *)p;
    varobj = (PyVarObject *)p;
    size = varobj->ob_size;

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", PyUnicode_AsUTF8(PyObject_Str(p)));

    printf("  first 10 bytes: ");
    for (i = 0; i < size && i < 10; ++i)
    {
        printf("%02x ", (unsigned char)bytes->ob_sval[i]);
    }
    printf("\n");
}

void print_python_float(PyObject *p)
{
    PyFloatObject *flt;

    printf("[.] float object info\n");

    if (!PyFloat_Check(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    flt = (PyFloatObject *)p;

    printf("  value: %f\n", flt->ob_fval);
}

