class sorted_sc_array {
public:
    sorted_sc_array() : size_(0), ptr_(nullptr), capacity(255) {
        ptr_ = new signed char[capacity+1];
    }

    ~sorted_sc_array() { delete[] ptr_; }


    sorted_sc_array(const sorted_sc_array& A) : size_(A.size_), capacity(A.capacity){
        if (size_ == 0) ptr_ = nullptr;
        else {
            ptr_ = new signed char[size_];
            std::copy(A.ptr_, A.ptr_ + size_, ptr_);

        }
    }


    sorted_sc_array& operator=(const sorted_sc_array& A) {
        if (this == &A) return *this; // self-assignment
        delete[] ptr_;
        size_ = A.size_;
        capacity = A.capacity;
        if (size_ == 0) ptr_ = nullptr;
        else {
            ptr_ = new signed char[size_];
            std::copy(A.ptr_, A.ptr_ + size_, ptr_);
        }
        return *this;
    }

    // RETURNS SIZE OF THE ARRAY (i.e. HOW MANY ELEMENTS IT STORES)
    int size() const {

        return size_; }

    // RETURNS RAW POINTER TO THE ACTUAL DATA, CAN BE INVOKED AT ANY TIME
    const signed char* data() const {

        std::sort(ptr_, ptr_+size_);

        return ptr_;
    }


    // AFTER INSERT COMPLETES THE ARRAY MUST BE IN ASCENDING ORDER
    void insert(signed char c) {
        if(size_ == capacity){
            capacity = capacity * 2;
            auto * temp = new signed char[capacity+1];
            std::copy(ptr_,ptr_+size_,temp);
            delete [] ptr_;
            ptr_=temp;
            ptr_[size_] = c;
            size_+=1;
        }
        else {
            ptr_[size_] = c;
            size_ += 1;
        }
    }


private:

    int size_;         // size of the array
    signed char* ptr_; // pointer to the array
    int capacity;
}; // class sorted_sc_array
