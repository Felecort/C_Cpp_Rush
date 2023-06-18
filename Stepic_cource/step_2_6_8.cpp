char *resize(const char *str, unsigned size, unsigned new_size)
{
	char *new_str = new char[new_size];
    size = (size > new_size) ? new_size : size;

    for (unsigned i = 0; i < size; i++){
        new_str[i] = str[i];
    }
    delete [] str;
    str = nullptr;
    return new_str;
}