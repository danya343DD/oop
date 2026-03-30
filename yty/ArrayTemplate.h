#include <stdexcept>

using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int count;
    int grow;

public:
    Array() : data(nullptr), size(0), count(0), grow(1) {}

    ~Array() {
        delete[] data;
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize, int newGrow = 1) {
        grow = newGrow;
        if (newSize == size) return;

        T* newData = nullptr;
        if (newSize > 0) {
            newData = new T[newSize];
            int elementsToCopy = (newSize < count) ? newSize : count;
            for (int i = 0; i < elementsToCopy; ++i) {
                newData[i] = data[i];
            }
        }

        delete[] data;
        data = newData;
        size = newSize;
        if (count > size) count = size;
    }

    int GetUpperBound() const {
        return count - 1;
    }

    bool IsEmpty() const {
        return count == 0;
    }

    void FreeExtra() {
        if (count < size) {
            SetSize(count, grow);
        }
    }

    void RemoveAll() {
        delete[] data;
        data = nullptr;
        size = 0;
        count = 0;
    }

    T GetAt(int index) const {
        if (index < 0 || index >= count) throw out_of_range("");
        return data[index];
    }

    void SetAt(int index, T value) {
        if (index < 0 || index >= size) throw out_of_range("");
        data[index] = value;
        if (index >= count) count = index + 1;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) throw out_of_range("");
        if (index >= count) count = index + 1;
        return data[index];
    }

    void Add(T value) {
        if (count >= size) {
            SetSize(size + grow, grow);
        }
        data[count++] = value;
    }

    void Append(const Array<T>& other) {
        int newCount = count + other.count;
        if (newCount > size) {
            SetSize(newCount, grow);
        }
        for (int i = 0; i < other.count; ++i) {
            data[count++] = other.data[i];
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            count = other.count;
            grow = other.grow;
            if (size > 0) {
                data = new T[size];
                for (int i = 0; i < count; ++i) {
                    data[i] = other.data[i];
                }
            }
            else {
                data = nullptr;
            }
        }
        return *this;
    }

    T* GetData() const {
        return data;
    }

    void InsertAt(int index, T value) {
        if (index < 0 || index > count) throw out_of_range("");
        if (count >= size) {
            SetSize(size + grow, grow);
        }
        for (int i = count; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        count++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= count) throw out_of_range("");
        for (int i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        count--;
    }
};

