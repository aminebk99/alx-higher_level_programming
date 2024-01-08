#include <Python.h>

/**
 * print_python_list_info - prints basic info about Python lists.
 * @p: Python list
 */
void print_python_list_info(PyObject *p)
{
    int size, alloc, i;
    PyObject *obj;

    size = Py_SIZE(p);
    alloc = ((PyListObject *)p)->allocated;

    printf("[*] Size of the Python List = %d\n", size);
    printf("[*] Allocated = %d\n", alloc);

    for (i = 0; i < size; i++)
    {
        obj = PyList_GetItem(p, i);
        printf("Element %d: %s\n", i, Py_TYPE(obj)->tp_name);
    }
}

