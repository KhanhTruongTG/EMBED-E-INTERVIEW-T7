# LÝ THUYẾT C PROGRAMMING LANGUAGE
  ## B1: C BASIC
  ### Biến
    - Embedded sẽ sử dụng thư viện #include <stdint.h>
    - uint8_t, uint16_t, uint32_t, uint64_t
    - VD: kích thước của biến uint32_t var;  0 -> 2^32-1
          kích thước của biến int32_t var;   (-2^32)/2 -> (2^32)/2-1
  ### Typedef
    - Đặt tên khác cho kiểu dữ liệu
    - VD: typedef int typeInt -> typeInt: được định nghĩa lại nhưng bản chất vẫn là kiểu dữ liệu int
    - VD: uint8_t: được định nghĩa từ kiểu unsighed char
  ### Hàm
    - Chương trình có tính lặp đi lặp lại sẽ được định nghĩa thành 1 hàm
    - Note: trừ 'void' thì tất cả các kiểu dữ liệu khác đều phải trả về giá trị (return + giá trị)
    - VD: 
      int tong(int a, int b){
        return a+b;
      }
  ### Struct
    - Kiểu cấu trúc, kiểu dữ liệu do người dùng tự định nghĩa, có thể trả về nhiều kết quả
    - VD: 
      struct toaDo{
        uint8_t x;
        uint8_t y;
      };
      int main(){
        struct toaDo diemM;
        diemM.x = 10;
        diemM.y = 20;
        printf("toa do diem M: M.x = %d, M.y = %d\n", diemM.x, diemM.y);
        return 0;
      }
  ### Câu điều kiện
    - for(khởi tạo; điều kiện; thuật toán)
    - if, else if, else
    - while (điều kiện)
    - do ... while
    - switch ... case
    - Break: câu lệnh thoát khỏi vòng lặp
    - Continue: câu lệnh bắt đầu vòng lặp mới, các lệnh phía dưới nó sẽ bị bỏ qua
  ### Enum
    - Cú pháp: Enum Tên {mem1, mem2, ..., memN};
      + Gía trị của các phần tử sẽ bằng 0 -> N-1 nếu không gán giá trị ban đầu
      + Giá trị của phần tử sau sẽ tăng lên 1 đơn vị so với phần tử đứng trước
      
  ## B2: POINTER
  ### Pointer
    - Khai báo con trỏ: Kiểu dữ liệu* Tên;
    - VD: int* ptr;
    - Con trỏ đặc biệt: Void* ptr; -> là con trỏ đặc biệt có thể trỏ được mọi đối tượng, nhưng nó KHÔNG BIẾT được địa chỉ đang trỏ tới có kiểu dữ liệu gì
    - Kích thước của con trỏ phụ thuộc vào KIẾN TRÚC của VI XỬ LÝ
    => Ép kiểu dữ liệu cho con trỏ: (int*)ptr;
       Lấy giá trị *(int*)ptr;
  ### Function Pointer
    - Trỏ đến địa chỉ hàm
    - VD: void (*ptr) (int,int); : ptr là con trỏ hàm có kiểu trả về là void và có kiểu input là (int,int)
    - VD: 
    void tong(int a, int b){
      printf("tong %d va %d = %d\n", a, b, a+b);
    }
    int main(){
    void (*ptr)(int,int);
    ptr = &tong;
    ptr(9,7);
    return 0;
    }
    => Ép kiểu về con trỏ hàm: 
    (void (*) (int,int))ptr
  ### NULL Pointer
    - Khai báo con trỏ phải gán giá trị ban đầu
    - Nếu khai báo chưa sử dụng phải gán = NULL
    - NULL là con trỏ có giá trị = 0 và có địa chỉ = 0
    - Và khi sử dụng xong cũng phải trả về NULL
  ### Pointer to Pointer
    - VD:
        int value = 100;
        int *ptr = &value;
        int **p_to_p = &ptr;
    - Con trỏ cấp 2 vẫn là một con trỏ, nên khi truy xuất giá trị của p_to_p chúng ta lấy được địa chỉ mà nó trỏ đến (địa chỉ của biến ptr)
    - p_to_p tương đương với &ptr: chính là địa chỉ mà con trỏ cấp 2 trỏ tới, hay chính là địa chỉ của con trỏ ptr
    - *p_to_p tương đương với ptr: chính là giá trị của con trỏ ptr, hay cũng chính là địa chỉ ô nhớ mà ptr trỏ tới, cũng chính là địa chỉ của biến value
    - **p_to_p tương đương với *ptr hay chính là giá trị ô nhớ mà con trỏ ptr trỏ tới, cũng chính là giá trị của biến value
  

  
  ## B3: MEMORY ALLOCATION
  ## B4: VARIABLE
  ## B5: STRUCT & UNION
  ## B6: COMPILER
  



# LÝ THUYẾT C++ PROGRAMMING LANGUAGE




# LÝ THUYẾT EMBEDDED



