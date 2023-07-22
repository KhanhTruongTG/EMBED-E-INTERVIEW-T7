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
  ![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/75fdc9f2-d420-4b01-92d4-ec2f3204be74)
  
  Trên RAM có 5 phân vùng bộ nhớ: Text, Data, BSS, Heap, Stack
  ### Text
  - Quyền truy cập chỉ Read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction
  - Chứa khai báo hằng số trong chương trình (.rodata)
  ### Data (Initialized Data)
  - Quyền truy cập là read-write
  - Chứa biến toàn cục hoặc biến static với giá trị khởi tạo KHÁC 0
  - Được giải phóng khi kết thúc chương trình
  => Tính từ lần đầu tiên khai báo. VD: ban đầu khởi tạo ở Data thì sẽ ở Data
  ### BSS (Uninitialized Data)
  - Quyền truy cập là read-write
  - Chứa biến toàn cục hoặc biến static với giá trị khởi tạo BẰNG 0 hoặc KHÔNG KHỞI TẠO
  - Được giải phóng khi kết thúc chương trình
  => Tính từ lần đầu tiên khai báo. VD: ban đầu khởi tạo ở BSS thì sẽ ở BSS
  ### Heap
  - Quyền truy cập là read-write
  - Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
  - Sẽ được giải phóng khi gọi hàm free,…
  ### Stack
  - Quyền truy cập là read-write
  - Được sử dụng cấp phát cho biến local, input parameter của hàm,…
  - Sẽ được giải phóng khi ra khỏi block code/hàm
  #### So sánh Heap và Stack
  - Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi
  - Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch
  - Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
  - Kích thước vùng nhớ
  
  Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn)
  Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình
  
  - Đặc điểm vùng nhớ
    + Stack: Vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình
    + Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ
  NOTE: Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian

  - Vấn đề lỗi xảy ra đối với vùng nhớ
    + Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
    
    VD: Tràn bộ nhớ Stack với hàm đệ quy vô hạn:
    int foo(int x){
    return foo(x);
    }
    + Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow), nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại
    
    VD: Trường hợp khởi tạo vùng nhớ Heap quá lớn:
    int *A = (int *)malloc(18446744073709551615);
  ### Cấp phát động
  - Malloc/Calloc: trả về con trỏ void (void*) nên cần ép kiểu dữ liệu trả về
  - Realloc: thay đổi kích thước ô nhớ
  
    VD: uint8_t *ptr = (uint8_t *)malloc(5); -> Malloc tạo 5 ô nhớ mỗi ô nhớ 1 byte

  Tổng quát:
  - Malloc: uint8_t * ptr = (uint8_t *)malloc(5 * sizeof(uint8_t));
  - Calloc: uint8_t * ptr = (uint8_t *)calloc(5, sizeof(uint8_t));
  - Thay đổi kích thước ô nhớ Realloc: ptr = (uint8_t *)realloc(ptr, 7 * sizeof(uint8_t));
  - Giải phóng: free(ptr);
  ## B4: VARIABLE
  ### Static
  Được lưu ở Data/BSS
  - Cục bộ:
    + Khi 1 biến được khai báo Static thì sẽ chỉ khởi tạo 1 lần duy nhất và tồn tại suổt thời gian chạy chương trình
    + Giá trị không bị mất đi khi kết thúc chương trình mà chỉ bị thu hồi bởi Data/BSS
    + Chỉ có thể gọi nội bộ trong hàm khởi tạo nó
    + Mỗi lần gọi giá trị của nó sẽ bằng giá trị gần nhất hàm được gọi
    + Static cục bộ thường dùng cho hàm có tham số trả về là địa chỉ
   VD:
      int* ptr(){
        int a = 10;
        return &a; //error
      }
    ->  Do a được khai báo nằm trên vùng Stack thoát khỏi hàm sẽ bị thu hồi địa chỉ
      int* ptr(){
        static int a = 10;
        return &a;
      }
    -> Do a được khai báo Static nên khi thoát ra khỏi hàm thì vẫn tônd tại -> trả về địa chỉ của a
  - Toàn cục:
    + Chỉ được sử dụng trong File chứa nó, KHÔNG CÓ CÁCH NÀO LẤY ĐƯỢC để sử dụng cho chương trình khác chung Folder
    + Static toàn cục thường sử dụng để xây dựng thư viện để người dùng không thay đổi được tránh bị sai lệch
  ### Extern
  - Dùng để lấy hàm/biến có sẵn của các File khác cùng 1 Folder để sử dụng trừ STATIC
  - Có thể khai báo toàn cục hay cục bộ đều được






  
  ## B5: STRUCT & UNION
  ## B6: COMPILER
  



# LÝ THUYẾT C++ PROGRAMMING LANGUAGE




# LÝ THUYẾT EMBEDDED



