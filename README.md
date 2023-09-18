## C PROGRAMMING LANGUAGE

<details> <summary> C BASIC </summary> 
  
### 1. Kiểu dữ liệu
    
    - Embedded sẽ sử dụng thư viện #include <stdint.h>
      
    - uint8_t, uint16_t, uint32_t, uint64_t
    
    - VD: kích thước của biến uint32_t var;  0 -> 2^32-1
          kích thước của biến int32_t var;   (-2^32)/2 -> (2^32)/2-1
  
### 2. Typedef
      
    - Đặt tên khác cho kiểu dữ liệu
    - VD: typedef int typeInt -> typeInt: được định nghĩa lại nhưng bản chất vẫn là kiểu dữ liệu int
    - VD: uint8_t: được định nghĩa từ kiểu unsighed char

### 3. Hàm 
  
    - Chương trình có tính lặp đi lặp lại sẽ được định nghĩa thành 1 hàm
    - Note: trừ 'Void' thì tất cả các kiểu dữ liệu khác đều phải trả về giá trị (return + giá trị)
    - VD: 
      int tong(int a, int b){
        return a+b;
      }

### 4. Struct
  
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
      
### 5. Vòng lặp / Câu điều kiện
 
    - for(khởi tạo; điều kiện; thuật toán)
    - if, else if, else
    - while (điều kiện)
    - do ... while
    - switch ... case
    - Break: câu lệnh thoát khỏi vòng lặp
    - Continue: câu lệnh bắt đầu vòng lặp mới, các lệnh phía dưới nó sẽ bị bỏ qua

### 6. Enum

    - Cú pháp: Enum Tên {mem1, mem2, ..., memN};
      + Gía trị của các phần tử sẽ bằng 0 -> N-1 nếu không gán giá trị ban đầu
      + Giá trị của phần tử sau sẽ tăng lên 1 đơn vị so với phần tử đứng trước
  
</details>    

<details> <summary> POINTER </summary> 

### 1. Pointer
      
    - Khai báo con trỏ: Kiểu dữ liệu* Tên;
    - VD: int* ptr;
    - Con trỏ đặc biệt: Void* ptr; 
    -> là con trỏ đặc biệt có thể trỏ được mọi đối tượng, nhưng nó KHÔNG BIẾT được địa chỉ đang trỏ tới có kiểu dữ liệu gì
    - Kích thước của con trỏ phụ thuộc vào KIẾN TRÚC của VI XỬ LÝ
    => Ép kiểu dữ liệu cho con trỏ: (int*)ptr;
       Lấy giá trị *(int*)ptr;

### 2. Function Pointer
  
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

### 3. NULL Pointer
    
    - Khai báo con trỏ phải gán giá trị ban đầu
    - Nếu khai báo chưa sử dụng phải gán = NULL
    - NULL là con trỏ có giá trị = 0 và có địa chỉ = 0
    - Và khi sử dụng xong cũng phải trả về NULL

### 4. Pointer to Pointer
 
    - VD:
        int value = 100;
        int *ptr = &value;
        int **p_to_p = &ptr;
    - Con trỏ cấp 2 vẫn là một con trỏ, nên khi truy xuất giá trị của p_to_p chúng ta lấy được địa chỉ mà nó trỏ đến (địa chỉ của biến ptr)
    - p_to_p tương đương với &ptr: chính là địa chỉ mà con trỏ cấp 2 trỏ tới, hay chính là địa chỉ của con trỏ ptr
    - *p_to_p tương đương với ptr: chính là giá trị của con trỏ ptr, hay cũng chính là địa chỉ ô nhớ mà ptr trỏ tới, cũng chính là địa chỉ của biến value
    - **p_to_p tương đương với *ptr hay chính là giá trị ô nhớ mà con trỏ ptr trỏ tới, cũng chính là giá trị của biến value

</details> 

<details> <summary> MEMORY ALLOCATION </summary>

  ![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/75fdc9f2-d420-4b01-92d4-ec2f3204be74)
  
  Trên RAM có 5 phân vùng bộ nhớ: Text, Data, BSS, Heap, Stack

### 1. Text

  - Quyền truy cập chỉ Read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction
  - Chứa khai báo hằng số trong chương trình (.rodata)

### 2. Data (Initialized Data)

  - Quyền truy cập là read-write
  - Chứa biến toàn cục hoặc biến static với giá trị khởi tạo KHÁC 0
  - Được giải phóng khi kết thúc chương trình
  => Tính từ lần đầu tiên khai báo. VD: ban đầu khởi tạo ở Data thì sẽ ở Data

### 3. BSS (Uninitialized Data)

  - Quyền truy cập là read-write
  - Chứa biến toàn cục hoặc biến static với giá trị khởi tạo BẰNG 0 hoặc KHÔNG KHỞI TẠO
  - Được giải phóng khi kết thúc chương trình
  => Tính từ lần đầu tiên khai báo. VD: ban đầu khởi tạo ở BSS thì sẽ ở BSS

### 4. Heap

  - Quyền truy cập là read-write
  - Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, …
  - Sẽ được giải phóng khi gọi hàm free,…

### 5. Stack

  - Quyền truy cập là read-write
  - Được sử dụng cấp phát cho biến local, input parameter của hàm,…
  - Sẽ được giải phóng khi ra khỏi block code/hàm

### 6. So sánh Heap và Stack

  - Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi
  - Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch
  - Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C)
  - Kích thước vùng nhớ
  
  **Stack**: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn)
  **Heap**: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình
  
  - *Đặc điểm vùng nhớ*
    + **Stack**: Vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình
    + **Heap**: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ
  
  NOTE: Việc tự động dọn vùng nhớ còn tùy thuộc vào trình biên dịch trung gian

  - *Vấn đề lỗi xảy ra đối với vùng nhớ*
    + **Stack**: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...

    VD: Tràn bộ nhớ Stack với hàm đệ quy vô hạn:
        
        int foo(int x){

          printf("De quy vo han\n");
    
          return foo(x);
    
        }

    + **Heap**: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow), nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại
    
    VD: Trường hợp khởi tạo vùng nhớ Heap quá lớn:
    
        int *A = (int *)malloc(18446744073709551615);

### 7. Cấp phát động

  - Malloc/Calloc: trả về con trỏ void (void*) nên cần ép kiểu dữ liệu trả về
  - Realloc: thay đổi kích thước ô nhớ

    VD:
    
      uint8_t *ptr = (uint8_t *)malloc(5);
      -> Malloc tạo 5 ô nhớ mỗi ô nhớ 1 byte

  *Tổng quát*:
  - **Malloc**: uint8_t * ptr = (uint8_t *)malloc(5 * sizeof(uint8_t));
  - **Calloc**: uint8_t * ptr = (uint8_t *)calloc(5, sizeof(uint8_t));
  - Thay đổi kích thước ô nhớ **Realloc**: ptr = (uint8_t *)realloc(ptr, 7 * sizeof(uint8_t));
  - Giải phóng: free(ptr);

</details> 

<details> <summary> VARIABLE </summary>

### 1. Static

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
        
        return &a; // ERROR
        
      }
    ->  Do a được khai báo nằm trên vùng Stack thoát khỏi hàm sẽ bị thu hồi địa chỉ
    
      int* ptr(){
      
        static int a = 10;
        
        return &a; // OK
        
      }
    -> Do a được khai báo Static nên khi thoát ra khỏi hàm thì vẫn tồn tại -> trả về địa chỉ của a
  - Toàn cục:
    + Chỉ được truy cập và sử dụng trong File chứa nó, KHÔNG CÓ CÁCH NÀO LẤY ĐƯỢC để sử dụng cho chương trình khác chung Folder
    + Static toàn cục thường sử dụng để xây dựng thư viện để người dùng không thay đổi được tránh bị sai lệch
  
### 2. Extern

  - Dùng để lấy hàm/biến có sẵn của các File khác cùng 1 Folder để sử dụng trừ STATIC
  - Có thể khai báo toàn cục hay cục bộ đều được

  -> Dùng lệnh `gcc filename1.c filename2.c -o filename3` để tạo filename3 từ filename1.c và filename2.c

  -> Để chạy filename3 dùng lệnh `./filename3`

### 3. Volatile

  - Trong lập trình nhúng (Embedded System), ta rất thường hay gặp khai báo biến với từ khóa volatile
  - Việc khai báo biến volatile là rất cần thiết để tránh những lỗi sai khó phát hiện do tính năng optimization của compiler

### 4. Register

  - Dùng để lưu Data, thông tin giống như RAM nhưng bộ nhớ ít hơn RAM, tốc độ nhanh hơn RAM do chỉ giao tiếp với ALU

   ALU <- Register <- RAM **(1)**
  
   **(2)** ALU -> Register -> RAM
  
  => Giải thích: bắt đầu từ **(1)**, 1 biến được khai báo sẽ lưu trên RAM -> RAM gửi thông tin về Register -> Register gửi thông tin về ALU -> ALU thực hiện thuật toán -> **(2)** ALU trả về Register -> Register trả về và lưu giá trị trên RAM 

</details>

<details> <summary> STRUCT - UNION </summary>
  
***Struct** & **Union** là kiểu dữ liệu do người dùng tự định nghĩa*
  
### 1. Struct

  Bộ nhớ của Struct được tính bằng cách tính tổng tối thiểu các thành viên cộng lại vì còn phụ thuộc bộ nhớ đệm (Padding)
  
### 2. Union

  Bộ nhớ của Union được tính bằng cách lấy phần tử có kích thước dữ liệu lớn nhất
  Các phần tử đều xài chung 1 bộ nhớ và có chung 1 địa chỉ

### 3. So sánh Struct và Union

  Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt như sau:
  
  - Struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau
  -> Do đó kích thước của 1 Struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding)

  - Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ
  -> Do đó kích thước của Union được tính là kích thước lớn nhất của kiểu dữ liệu trong Union, việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác

</details>

<details> <summary> COMPILER </summary>

  - Quy trình biên dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao (NNBC) (C/C++, Pascal, Java, C#…) sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi 
  - Ngôn ngữ lập trình C là một ngôn ngữ dạng biên dịch
  - Chương trình được viết bằng C muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi
  - Quá trình được chia ra làm 4 giai đoạn chính:
    + Giai đoạn tiền xử lý (Pre-processor)
    + Giai đoạn dịch NNBC sang Assembly (Compiler)
    + Giai đoạn dịch Assembly sang ngôn ngữ máy (Assember)
    + Giai đoạn liên kết (Linker)
  
  ![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/e920ad72-a979-450c-8353-243055c88ce5)

  ![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/5354cfc4-a723-434e-b080-bf5669424864)

### 1. Giai đoạn tiền xử lý (Pre-processor)

  Giai đoạn này sẽ thực hiện:
  - Nhận mã nguồn
  - Xóa bỏ tất cả chú thích, comments của chương trình
  - Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
  
    -> Sau khi qua tiền xử lý thì file code sẽ có dạng `.i`

    -> Dùng lệnh `gcc -E filename.c -o filename.i` hoặc `gcc -E filename.i` để xem lại code sau quá trình tiền xử lý
    
  VD: Chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình

### 2. Giai đoạn dịch NNBC sang Assembly (Compiler)
  
  - Phân tích cú pháp (syntax) của mã nguồn NNBC
  - Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý

    -> Quá trình biên dịch code `.i` thành ngôn ngữ Assembly `.s`

    -> Dùng lệnh `gcc filename.i -S -o filename.s` hoặc `gcc -c -S filename.c` để xem lại code sau quá trình biên dịch

### 3. Giai đoạn dịch Assembly sang ngôn ngữ máy (Assember)
  
  - Dich chương trình => Sang mã máy 0 và 1
  - Một tệp mã máy (Object) `.o` hoặc `.obj` sinh ra trong hệ thống sau đó
    -> Dùng lệnh `gcc -c filename.c -o filename.o` để tạo ra file `.o` và dùng lệnh `objdump -d -Mintel filename.o` để xem code

### 4. Giai đoạn liên kết (Linker)
  
  - Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file `.c` hoặc file thư viện `.lib`) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
  - Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này
  - Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết
  - Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (`Executable` hay `.exe`) thống nhất

  -> File sau khi gộp lại sẽ có đuôi mở rộng `Executable` hoặc `.exe` trên Window, còn trên MacOS hay Linux có thể đuôi theo chỉ định hoặc không có đuôi mở rộng

  -> Để chạy file code C trên Terminal dùng lệnh `gcc -o filename.exe filename.c` để tạo ra file thực thi, sau đó dùng lệnh `./filename` để chạy file thực thi

</details>

<details> <summary> MACRO - FUNCTION - INLINE FUNCTION </summary>

### MACRO

  - Marco là 1 tên bất kì (do lập trình viên đặt tên) trỏ tới 1 khối lệnh thực hiện một chức năng nào đó
  - Trong quá trình tiền xử lí (pre-processor), các Macro được sử dụng trong chương trình được thay thế bởi các khối câu lệnh tương ứng
  - Định nghĩa macro bằng lệnh `#define`
  - Được xử lí bởi Preprocessor 
  - VD:

    `#define SUM(a,b) a+b`-> Preprocessor khi gặp bất kỳ lời gọi `SUM(a, b)` nào thì thay ngay bằng `a+b`

  => Macro định nghĩa cái gì thì sẽ thay thế cái đó trong quá trình tiền xử lý

### FUCTION

  - Function là một đoạn chương trình có tên, đầu vào và đầu ra. Hàm có chức năng giải quyết một số vấn đề chuyên biệt cho chương trình chính. Hàm được gọi nhiều lần với các tham số khác nhau
       
      + Program counter: bộ đếm lấy giá trị và đọc giá trị đó (chỉ đếm và đọc giá trị). NOTE: bước nhảy phụ phuộc vào kiến trúc vi xử lí
      + Stack pointer: bộ nhớ để lưu địa chỉ 
  - Đầu tiên chương trình sẽ chạy các lệnh một cách tuần tự từ địa chỉ (Program counter sẽ đếm từ địa chỉ) -> Khi thấy hàm được gọi -> Compiler sẽ phải lưu địa chỉ sau hiện tại (địa chỉ trước hàm được gọi) vào Stack (Stack Pointer) -> chuyển Program counter tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về -> sau đó quay lại vị trí đã lưu trong Stack poiter trước khi gọi hàm và tiếp tục thực hiện chương trình
  - Điều này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được Compile (tức là Inline Function)

  - **Inline Function** được khai báo với từ khóa `Inline`
  - Khi Compiler thấy bất kỳ chỗ nào xuất hiện Inline Function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compile tương ứng –> Phần được thay thế không phải code mà là đoạn mã đã được compile
  - Được xử lí bởi Compiler

### SO SÁNH MACRO - FUNCTION - INLINE FUNCTION

| SO SÁNH | MACRO | FUNCTION | INLINE FUNCTION |
|--------------|-------|------|-------|
| Tốc độ | nhanh | chậm | nhanh nhưng thông qua compile | 2 x 4 |
| Kích thước chương trình| lớn | nhỏ | lớn | 3 x 4 |

  - Macro đơn giản là chỉ thay thế đoạn code macro vào chỗ được gọi trước khi được biên dịch
  - Inline Function thay thế đoạn mã code đã được biên dịch vào chỗ được gọi
  - Function bình thường phải tạo một Function call, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình
  - Macro khiến kích thước bộ nhớ chương trình lớn nhưng thời gian chạy nhanh -> tốc độ nhanh, kích thước lớn (code dài hơn -> file dài hơn)
  - Inline Function khiến kích thước bộ nhớ chương trình lớn, tuy nhiên nó làm giảm thời gian chạy chương trình -> tốc độ nhanh, kích thước lớn
  - Function bình thường sẽ phải gọi Function call nên tốn thời gian hơn Inline Function nhưng kích thước chương trình nhỏ -> tốc độ sẽ chậm, kích thước nhỏ (code ngắn hơn -> file ngắn hơn)

</details>

<details> <summary> EXTRA KNOWLEDGE </summary>

### CON TRỎ HẰNG

```sh
int x = 10, y = 20;
const int *px = &x;
*px = 15;  // ERROR do cố ghi lại giá trị cho vùng nhớ qua con trỏ hằng
px = &y;   // OK
x = 15;    // OK
```
  - Khi ta khai báo 1 con trỏ có thêm từ khóa const phía trước như trên. Ta hiểu rằng con trỏ px là 1 con trỏ hằng
  - Con trỏ hằng là con trỏ có thể trỏ đến 1 vùng nhớ hằng
  - Đặc điểm của con trỏ này là nó là con trỏ chỉ đọc (read-only), người dùng có thể thông qua nó đọc giá trị vùng nhớ mà nó trỏ đến nhưng **không thể thông qua nó ghi lại giá trị vào vùng nhớ đó**

### HẰNG CON TRỎ

```sh
int x = 10, y = 20;
int* const px = &x;
*px = 15;  // OK
px = &y;   // ERROR vì cố tình chuyển đổi địa chỉ trỏ của con trỏ
```
  - Khi khai báo như trên là hiểu con trỏ px là 1 hằng con trỏ
  - Đặc điểm của con trỏ này là nó chỉ có thể trỏ đến 1 địa chỉ duy nhất và sau đó không thể thay đổi địa chỉ trỏ được nữa
  - Khác với **con trỏ hằng** thì hằng con trỏ **có thể đọc ghi giá trị vùng nhớ thông qua chính bản thân con trỏ đó**

### CONST TRONG FUNCTION - HIỂU THÊM VỀ PHÂN VÙNG NHỚ

```sh
void test(){
  const int a = 10;    //tất cả các biến khai báo cục bộ đều được lưu ở phân vùng Stack
}
```
***=> Các biến khai báo liên quan đến các phân vùng nhớ Text, Data, BSS thì khai báo toàn cục mới có hiệu lực***

***=> Tất cả các biến khai báo cục bộ đều được lưu ở phân vùng Stack***


```sh
int arr[3] = {1, 3, 5};
void string(const int arr[]){      //không muốn thay đổi giá trị arr, chỉ được phép đọc
}
```
***=> Khi ta KHÔNG muốn thay đổi giá trị của biến toàn cục/ biến cục bộ/ biến input thì ta sử dụng Const***

</details>


## C++ PROGRAMMING LANGUAGE

<details> <summary> C++ BASIC </summary>

***C++** cũng tương tự như **C**, cũng có các lệnh cơ bản như C, `include` thư viện để sử dụng các hàm, cũng có các kiểu dữ liệu tương tự như C,...*
  - VD1:
```sh
#include <iostream>
using namespace std;

int main(){
  cout<<"HELLO\n";
  return 0;
}
```
  - VD2:
```sh
#include <iostream>
using namespace std;

int main(){
  int key = 0;
  cout<<"nhap key: ";
  cin>>key;
  cout<<"key = "<<key<<endl;
  return 0;
}
```

</details>

<details> <summary> CLASS </summary>

### CLASS

Class là kiểu dữ liệu cho người dùng tự định nghĩa tương tự như Struct, Union, Enum

Class là một mô tả trừu tượng (abstract) của nhóm các đối tượng (object) có cùng bản chất, ngược lại mỗi một đối tượng là một thể hiện cụ thể (instance) cho những mô tả trừu tượng đó. Một Class trong C++ sẽ có các đặc điểm sau:
  - Một Class bao gồm các thành phần dữ liệu (thuộc tính hay **property**) và các phương thức (hàm thành phần hay **method**)
  - Từ khóa Class sẽ chỉ điểm bắt đầu của một Class sẽ được cài đặt.
```sh
  VD: Một class đơn giản: Class Car
    - Một chiếc xe hơi vậy thì sẽ có chung những đặc điểm là đều có vô lăng, có bánh xe nhiều hơn 3, có động cơ... -> một Class
    - Một model hay mẫu mà người ta đã quy định là nếu đúng như vậy thì nó là xe hơi
    - Nhưng mà xe thì có thể có nhiều hãng khác nhau, BMW, Vinfast, Toyota... Thì mỗi hãng xe lại có những model xe khác nhau nhưng chúng đều là xe hơi
    - Vậy thì trong lập trình cũng vậy, Class là quy định ra một mẫu, một model mà các thể hiện của nó (instance) hay đối tượng (object) phải tuân theo
```
  - VD:
```sh
#include <iostream>
#include <string>
using namespace std;
class Person {
    public:
        string firstName;       // property
        string lastName;        // property
        int age;                // property

        void fullname() {       // method
            cout << firstName << ' ' << lastName;
        }
};
int main(){
  Person person;
  person.firstName = "Khanh";
  person.lastName = "Truong";
  person.fullname();            // sẽ in ra màn hình là "Khanh Truong"
  return 0;
}
```

### Access modifiers & Properties declaration
  **Access modifier**
  - Là phạm vi truy cập của các thuộc tính và phương thức sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là ***public***, ***private*** và ***protected***
  - Các thuộc tính và phương thức khai báo **public** thì có thể được truy cập trực tiếp thông qua instance của class đó. Các thuộc tính nên khai báo là public nếu bạn ***không có ràng buộc điều kiện trước khi gán*** (**người dùng có thể thoải mái gán giá trị**) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc tính
  - Các thuộc tính **private** thường được sử dụng khi bạn ***không mong muốn*** người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về giá trị
  - Đối với **protected**, các phương thức và thuộc tính ***chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó***

  **Method declaration** là phương thức cũng giống như một hàm bình thường
  - Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong lúc định nghĩa class và định nghĩa thi hành bên ngoài class

  VD: Định nghĩa thi hành bên trong class
```sh
class Animal{
  public:
    string sound;
    void makeNoise(){
    cout << sound;
    }
};
```
  VD: Định nghĩa thi hành bên ngoài class
```sh
class Animal{
  public:
    string sound;
    void makeNoise();
};
void Animal::makeNoise(){
  cout << sound;
}
```
  **Constructor** (hàm tạo) là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta khởi tạo một object
  
  VD:
```sh
class Person{
  public:
    string firstName;
    string lastName;
    int age;

    Person(string _firstName, string _lastName, int _age){
      firstName = _firstName;
      lastName = _lastName;
      age = _age;
    }
    void fullname(){
      cout << firstName << ' ' << lastName;
    }
};
```
  **Destructor** (hàm hủy) việc được quản lý bộ nhớ một cách hoàn toàn do người lập trình làm chủ thì destructor là vô cùng cần thiết
  - Trong số thuộc tính của class bạn định nghĩa có một con trỏ, mảng động...nếu không sử dụng desctructor thì sẽ xảy ra chuyện rò rỉ bộ nhớ. Với destructor bạn có thể xóa con trỏ đi khi object được thu hồi hoặc bạn có thể gọi tường minh destructor
  
  VD:
```sh
class MyClass{
    public:
        MyClass(){                               // constructor
            cout << "Constructor is executedn";
        }
        ~MyClass(){                              // destructor
            cout << "Constructor is executedn";
        }
};
```
  **Static member** (thành viên tĩnh) trong class C++ cũng tương tự như với **static variable** (biến tĩnh) trong function
  - *Đối với function*, sau khi thực hiện xong khối lệnh và thoát thì static variable vẫn sẽ không mất đi
  - *Đối với class*, static member sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì **chỉ có một** và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là dùng chung một biến static

</details>

<details> <summary> FEATURE OF OBJECT ORIENTED PROGRAMMING (OOP) </summary>

### FEATURE OF OBJECT ORIENTED PROGRAMMING (OOP)
  OOP: là đặc tính của lập trình hướng đối tượng
  
  Có 4 đặc tính quan trọng của lập trình hướng đối tượng trong C++ cần nắm:
  - Inheritance (Tính kế thừa)
  - Polymorphism (Tính đa hình)
  - Abstraction (Tính trừu tượng)
  - Encapsulation (Tính đóng gói)

### Inheritance (Tính kế thừa)
  
  Tính kế thừa: một class có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó
  
  Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta sẽ gọi class con đó là *subclass* trong C++ và class cha chính là *superclass* trong C++
```sh
  Class cha có 3 phạm vi truy cập là private, protected, public
  Class con kế thừa theo kiểu
    - Public:
      + public class cha sẽ là public class con
      + protected class cha sẽ là protected class con
      + private không kế thừa được
    - Protected:
      + public class cha sẽ là protected class con
      + protected class cha sẽ là protected class con
      + private không kế thừa được
    - Private:
      + public class cha sẽ là private class con
      + protected class cha sẽ là private class con
      + private không kế thừa được
      -> Khi class con (1) kế thừa class cha theo kiểu private thì class con của class con (1) sẽ không kế thừa được các property hay method của class con (1)
```
### Polymorphism (Tính đa hình)
  
  Tính đa hình: là một khả năng mà một method trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy thuộc vào dữ liệu được xử lý. Tức các method có cùng tên nhưng các dữ liệu input khác nhau sẽ đưa ra các kết quả khác nhau

### Abstraction (Tính trừu tượng)
  
  Tính trừu tượng: là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý. Tức có thể xử lý một đối tượng bằng cách gọi tên một phương thức và trả về kết quả xử lý, mà không cần biết đối tượng đó đã được các thao tác như nào trong class

  VD: Có thể nấu cơm bằng nồi cơm điện bằng cách rất đơn giản là ấn công tắc nấu, mà không cần biết là bên trong cái nồi cơm điện đó đã làm thế nào mà gạo có thể nấu thành cơm
  
### Encapsulation (Tính đóng gói)

  Tính đóng gói: là khả năng không cho object truy cập trực tiếp đến property, nếu muốn truy cập đến property thì phải thông qua method, tránh trường hợp xử lí bị sai dữ liệu, nên sẽ đảm bảo tính toàn vẹn của object, cũng như giúp giấu đi các dữ liệu, thông tin cần được che giấu

  VD: Khi bạn dùng một cái Iphone, bạn không thể thay đổi các cấu trúc bên trong của hệ điều hành IOS, mà chỉ có Apple mới có thể làm được điều này
  
</details>

<details> <summary> VECTOR </summary>

### VECTOR

- Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp trong vector
- Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình
- **Array lưu ở Stack, Vector lưu ở Heap**
- Syntax: `vector <kiểu dữ liệu> ten-vector`

### Modifiers

  **1. push_back()**
  - `push_back()`: Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong `push_back()` không giống với kiểu của vector thì sẽ bị ném ra
  - Syntax: `ten-vector.push_back(ten-cua-phan-tu);`

  **2. assign()**
  - `assign()`: Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các giá trị cũ
  - Syntax: `ten-vector.assign(int size, int value);`

  **3. pop_back()**
  - `pop_back()`: Hàm `pop_back()` được sử dụng để xóa đi phần tử cuối cùng một vector

  **4. insert()**
  - `insert()`: Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bằng vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ

  **5. erase()**
  - `erase()`: Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa

  **6. emplace()**
  - `emplace()`: Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào

  **7. emplace_back()**
  - `emplace_back()`: Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector

  **8. swap()**
  - `swap()`: Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau

  **9. clear()**
  - `clear()`: Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector

</details>

<details> <summary> TEMPLATE </summary>

  - **Template** là một kiểu dữ liệu trừu tượng tổng quát cho các kiểu dữ liệu int, float, double, bool...
  - Có 2 loại đó là Function template & Class template
  - Template giúp người lập trình định nghĩa tổng quát cho Function và Class thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau
```sh
#include <iostream>
template <typename var1, typename var2>
var1 tong(var1 a, var2 b){
  return var1(a+b);
}
int main(){
    printf("tong a va b la %f\n", tong(3,5.6));
    //var 1 sẽ có kiểu dữ liệu là int, var2 có kiểu dữ liệu là double
    //tong trả về kiểu var1 nên sẽ có kiểu dữ liệu là int
    return 0;
}
```

</details>

<details> <summary> NAMESPACE </summary>

  - **Namespace** được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau
```sh
  - VD:
  + File A, include file thư viện B và file thư viện C
  + File B và C có cũng 1 function và có cùng input nhưng các function đó xử lí khác nhau
  + Khi file A `using namespace B` và `using namespace C` -> gọi function (giống nhau đó) -> báo lỗi => do file A không hiểu đang gọi function của `namespace` nào
```
```sh
  - VD:
#include <iostream>
using namespace std;
using namespace ConOngA;
namespace ConOngA{
  int Teo=10;
}
namespace ConOngB{
    int Teo=20;
}
int main(){
    cout << Teo << endl;            //cách gọi khi using namespace ConOngA
    //dòng này sẽ bị lỗi nếu sử dụng cả 2 using namespace ConOngA và using namespace ConOngB
    //-> vì nó không hiểu đang gọi Teo trong namespace nào

    cout << ConOngB::Teo << endl;   //cách gọi thủ công
    return 0;
}
```

</details>

<details> <summary> VIRTUAL FUNCTION </summary>

  - **Virtual function** là một hàm trong class mà class kế thừa cần phải định nghĩa lại, là một phần không thể thiếu để thể hiện tính đa hình trong kế thừa
```sh
#include <iostream>
class DoiTuong{
    public:
      virtual char *cmd(){
        return (char *)"doi tuong\n";
      }
      void Display(){
        printf("%s",cmd());
      }
};
class SinhVien : public DoiTuong{
    char* cmd(){
        return (char *)"sinhvien\n";
    }
};
int main(){
  DoiTuong dt;
  dt.Display();
  SinhVien sv;
  sv.Display();
  return 0;
}

//Nếu không sử dụng virtual
//SinhVien kế thừa DoiTuong nên khi trỏ sv.Display thì sẽ trỏ đến hàm Display ở DoiTuong
//cmd() trong Display ở DoiTuong đang trỏ đến char *cmd()
//Nên khi ta gọi sv.Display thì cũng sẽ hiển thị nội dung trong vùng của class DoiTuong

//Nếu sử dụng virtual
//Khi gọi sv.Display, thì cmd() sẽ xem ở class SinhVien đã đã có ghi đè (override) hay chưa
//Lúc đó virtual char *cmd() sẽ kiểm tra xem cmd() ở SinhVien có định nghĩa lại hay không
//Nếu có thì nó sẽ load lại chương trình được định mới nhất (overload)
```
=>Khi viết chương trình, nếu method nào cần phải load lại các định nghĩa mới nhất của các class con kế thừa thì ta sẽ sử dụng virtual

</details>

<details> <summary> LINKED LIST </summary>

  **Linked list** là một cấu trúc dữ liệu động, nó là một danh sách mà mỗi phần tử đều liên kết với phần tử đúng sau nó trong danh sách. Mỗi phần tử (được gọi là một node hay nút) trong danh sách liên kết đơn là một cấu trúc có hai thành phần:
  - Thành phần dữ liệu: lưu thông tin về bản thân phần tử đó
  - Thành phần liên kết: lưu địa chỉ phần tử đứng sau trong danh sách, nếu phần tử đó là phần tử cuối cùng thì thành phần này bằng NULL

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/83ad49ea-1e20-4234-8987-d6467667ddaf)

  Do danh sách liên kết đơn là một cấu trúc dữ liệu động, được tạo nên nhờ việc cấp phát động nên nó mang một số đặc điểm sau đây:
  - Được cấp phát bộ nhớ khi chạy chương trình
  - Có thể đổi thay kích thước qua việc thêm, xóa phần tử
  - Kích thước tối đa phụ thuộc vào bộ nhớ khả dụng của RAM
  - Các phần tử được lưu trữ tự nhiên (không liên tiếp) trong RAM

  Do tính liên kết của phần tử đầu và phần tử đứng sau nó trong danh sách liên kết đơn, nó có những đặc điểm sau:
  - Chỉ cần nắm được phần tử đầu và cuối là có thể quản lý được danh sách
  - Truy cập tới phần tử ngẫu nhiên phải duyệt từ đầu tới vị trí đó
  - Chỉ có thể tìm kiếm tuyến tính một phần tử

</details>

<details> <summary> MAP </summary>

  **Map** là một tập hợp các phần tử được sắp xếp theo thứ tự cụ thể, mà mỗi phần tử trong đó được hình thành bởi sự kết hợp của một cặp khóa và giá trị (key & value) với mỗi khóa là duy nhất trong map
  - Các `key` được sử dụng để sắp xếp và xác định `value` tương ứng được liên kết với nó
  - Mỗi `key` trong map là duy nhất và không được phép trùng lặp
  - Các `value` trong map thì có thể trùng lặp, chúng có thể thay đổi giá trị, cũng như là được chèn hoặc xóa khỏi map
  - Để sử dụng map bạn cần khai báo: `#include<map>`
  - Syntax: `map <kiểu dữ liệu, kiểu dữ liệu> tên biến;`
```sh
  Trả về kích thước hiện tại của map: m.size();
  Kiểm tra map có rỗng hoặc không: m.empty();     // trả về true nếu map rỗng, false nếu không rỗng
  Truy cập phần tử trong map: m[x];               // truy cập value của khóa x
  Chỉnh sửa phần tử trong map (phần tử chỉnh sửa phải ở dạng "cặp"): m.insert(x);
  Xóa phần tử trong map: m.erase(x);
  Xóa tất cả phần tử trong map: m.clear();
```

</details>

<details> <summary> LAMBDA </summary>

  **Lambda** là function nhưng được viết ở cục bộ (viết ở hàm main) thay vì khai báo ở toàn cục

  Syntax: `[danh sách các biến ngoài lambda](parameter list) -> kiểu trả về { các câu lệnh mà lambda sẽ thực thi}`
  
  VD:
```sh
#include <iostream>
int main(){
  int x = 20;
  auto tong = [x](int a, int b){
    printf("tong: %d\n", a+b);
    printf("x = %d\n, x);
  };
  tong(7, 9);
  return 0;
}
```

</details>


## EMBEDDED

<details> <summary> SPI </summary>

**SPI** (Serial Peripheral Interface) là một chuẩn truyền thông giao tiếp tốc độ cao do Motorola đề xuất
  - Các bit dữ liệu được truyền nối tiếp nhau và có xung clock đồng bộ
  - Giao tiếp song công, có thể truyền và nhận cùng một thời điểm
  - Khoảng cách truyền ngắn, được sử dụng để trao đổi dữ liệu với nhau giữa các chip trên cùng một bo mạch
  - Tốc độ truyền khoảng vài Mb/s
  - Các dòng vi điều khiển thường được tích hợp module giao tiếp SPI dùng để giao tiếp truyền dữ liệu với các vi điều khiển khác, hoặc giao tiếp với các ngoại vi bên ngoài như cảm biến, EEPROM, ADC, LCD, SD Card,...

#### Các thiết bị giao tiếp qua SPI có quan hệ Master - Slave
  - Master là thiết bị điều khiển (thường là vi điều khiển)
  - Slave (thường là cảm biến, màn hình hoặc chip nhớ) nhận lệnh từ master
  - Cấu hình đơn giản nhất của SPI là hệ thống một slave, một master duy nhất, nhưng một master có thể điều khiển nhiều hơn một slave

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/95436648-fe6f-4a97-a483-7ab9c40af85c)
***Kết nối trên một SPI bus với một master và một slave***

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/806255d5-77f1-4204-b132-6b261a4a3964)
***Kết nối từng slave độc lập (song song)***

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/feda85a3-4f9d-4bbc-a9ab-e6e4c7a4fc56)
***Kết nối slave theo chuỗi (nối tiếp)***

#### Bus SPI gồm có 4 đường tín hiệu
  - SCLK: Serial Clock (chân xung clock)
  - MOSI: Master Out, Slave In (truyền data đi cho slave)
  - MISO: Master In, Slave Out (nhận data từ slave)
  - SS: Slave Select (điều khiển để cho phép master điều khiển với slave nào)

#### Chân SS hoạt động
  - Thường Slave 1,2,3 là những con sensor do nhà sản xuất đã nạp chương trình SPI. Có những case ngoại lệ
  - Nếu SS1 kéo xuống mức 0 (truyền bit 0) thì nó cho phép SS1 master giao tiếp với slave 1. Nếu SS1 mức 1 thì không đc giao tiếp với slave 1
  - Nếu muốn master giao tiếp với slave 2, thì SS1 kéo lên mức 1, SS2 kéo xuống mức 0, SS3 kéo lên mức 1. Slave 3 tương tự

#### Các bước truyền dữ liệu SPI

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/263941e2-d3d4-41ee-8426-f4d40c3d8d7a)

<img src="https://arduinokit.vn/wp-content/uploads/2023/05/nguyen-ly-hoat-dong-chuan-giao-tiep-spi.webp">

  - Master ra tín hiệu xung nhịp
  - Master chuyển chân SS hoặc CS sang trạng thái điện áp thấp, điều này sẽ kích hoạt slave
  - Master gửi dữ liệu từng bit một tới slave dọc theo đường MOSI. Slave đọc các bit khi nó nhận được
  - Nếu cần phản hồi, slave sẽ trả lại dữ liệu từng bit một cho master dọc theo đường MISO. Master đọc các bit khi nó nhận được

#### Các chế độ hoạt động

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/a436699a-b1ae-4f46-9c86-1610b93d8477)

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/7f6adc20-f2a3-40d2-9500-e04748e7957f)

  - CPOL dùng để chỉ trạng thái của chân SCK ở trạng ban đầu. Chân SCK giữ ở mức cao khi CPOL=1 hoặc mức thấp khi CPOL=0
  - CPHA dùng để chỉ các mà dữ liệu được lấy mẫu theo xung. Dữ liệu sẽ được lấy ở cạnh lên của SCK khi CPHA = 0 hoặc cạnh xuống khi CPHA = 1
  + CPHA = 1: đầu tiên cho 1 xung clock trước, sau đó đưa dữ liệu vào, xung clock tiếp theo sẽ đẩy dữ liệu đi
  + CPHA = 0: đưa data vào trước, sau đó dùng xung clock để đẩy data đi

#### Ưu và nhược điểm của giao thức SPI

**Ưu điểm**
- Tốc độ truyền thông cao
- Giao tiếp đồng bộ
- Khả năng truyền thông hai chiều:  SPI cho phép truyền dữ liệu theo hai chiều, từ master tới slave và từ slave về master, như truyền thông với các cảm biến hoặc thiết bị ngoại vi
- Hỗ trợ nhiều thiết bị slave: SPI cho phép kết nối nhiều thiết bị slave với một master duy nhất. Master có thể chọn từng slave để truyền dữ liệu, giúp mở rộng khả năng kết nối và giao tiếp với nhiều thiết bị
- 
**Nhược điểm**
- Số lượng chân kết nối nhiều hơn các giao thức truyền thông khác như I2C
- Độ dài cáp bị giới hạn: Để SPI có tương phản cao và đạt được tốc độ truyền thông nhanh thì cần phải có độ dài cáp kết nối giữa các thiết bị cần được giới hạn để tránh sự mất mát dữ liệu và nhiễu
- Không hỗ trợ chia sẻ đường truyền: Điều này có nghĩa là chỉ một slave được truyền dữ liệu tại một thời điểm

</details>

<details> <summary> UART </summary>

**UART** là giao thức không đồng bộ, do đó không có đường clock nào điều chỉnh tốc độ truyền dữ liệu. Người dùng phải đặt cả hai thiết bị để giao tiếp ở cùng tốc độ. Tốc độ này được gọi là tốc độ truyền, được biểu thị bằng bit trên giây (bit/s)

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/ac1b85e2-db33-4ba2-9aeb-96460086d0ca)

  - Các UART giao tiếp giữa hai nút riêng biệt bằng cách sử dụng một cặp dẫn và một nối đất chung
  + TX: truyền dữ liệu
  + RX: nhận dữ liệu

  - Tại 1 thời điểm, UART có thể cùng truyền và nhận dữ liệu
  - Ở trạng thái không giao tiếp, chân TX luôn ở mức cao (có điện trở kéo lên)
  - UART là một giao thức một master, một slave. Trong đó một thiết bị được thiết lập để giao tiếp với duy nhất một thiết bị khác

#### Cách truyền, nhận dữ liệu

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/a94bb9eb-0a88-435d-84c3-31f12f9c66f7)

  - Dữ liệu truyền qua UART được tổ chức thành các gói. Mỗi gói chứa 1 bit start, 5 đến 9 bit dữ liệu (tùy thuộc vào UART, đa số là 8 bit), một bit chẵn lẻ tùy chọn và 1 hoặc 2 bit stop (đa số là 1 bit stop)
  + Start bit: để bắt đầu truyền dữ liệu, UART truyền sẽ kéo đường truyền từ mức cao xuống mức thấp trong một chu kỳ clock. Khi UART nhận phát hiện sự chuyển đổi điện áp cao xuống thấp (có thể delay nửa 1.5 chu kì cho dữ liệu ổn định), nó bắt đầu đọc các bit trong khung dữ liệu ở tần số của tốc độ truyền

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/95f8dd40-c8bc-4fa3-8aa6-905ca1a9f698)

  + Khung dữ liệu chứa dữ liệu thực tế được chuyển. Nó có thể dài từ 5 bit đến 8 bit nếu sử dụng bit chẵn lẻ. Nếu không sử dụng bit chẵn lẻ, khung dữ liệu có thể dài 9 bit. Trong hầu hết các trường hợp, dữ liệu được gửi với bit ít quan trọng nhất trước tiên (hoặc truyền từ LSB đến MSB)
  + Stop bit: để báo hiệu sự kết thúc của gói dữ liệu, UART gửi sẽ điều khiển đường truyền dữ liệu từ điện áp thấp đến điện áp cao trong ít nhất khoảng 1 bit (hoặc 2 bit)

**Bit chẵn lẻ**: là một cách để UART nhận cho biết liệu có bất kỳ dữ liệu nào đã thay đổi trong quá trình truyền hay không (bức xạ điện từ, tốc độ truyền không khớp hoặc truyền dữ liệu khoảng cách xa)
  - Sau khi UART nhận đọc khung dữ liệu, nó sẽ đếm số bit có giá trị là 1 và kiểm tra xem tổng số là số chẵn hay lẻ
    + Nếu bit chẵn lẻ là 0 (tính chẵn), thì tổng các bit 1 trong khung dữ liệu phải là một số chẵn
    + Nếu bit chẵn lẻ là 1 (tính lẻ), các bit 1 trong khung dữ liệu sẽ tổng thành một số lẻ
  - Khi bit chẵn lẻ khớp với dữ liệu, UART sẽ biết rằng quá trình truyền không có lỗi
  - Nhưng nếu bit chẵn lẻ là 0 và tổng là số lẻ hoặc bit chẵn lẻ là 1 và tổng là số chẵn, UART sẽ biết rằng các bit trong khung dữ liệu đã thay đổi

</details>

<details> <summary> I2C </summary>

**I2C** (Inter – Integrated Circuit) là 1 giao thức giao tiếp nối tiếp đồng bộ được phát triển bởi Philips Semiconductors, sử dụng để truyền nhận dữ liệu giữa các IC với nhau chỉ sử dụng hai đường truyền tín hiệu

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/055ef731-6980-4a46-b8d2-947b2243b6fc)

  - I2C chỉ sử dụng hai dây để truyền dữ liệu giữa các thiết bị:
    + SDA (Serial Data) - đường truyền cho master và slave để gửi và nhận dữ liệu
    + SCL (Serial Clock) - đường mang tín hiệu xung nhịp
  - I2C là một giao thức truyền thông nối tiếp, vì vậy dữ liệu được truyền từng bit dọc theo một đường duy nhất (đường SDA)
  - Khi Master và Slave không giao tiếp với nhau, chân SDA và SCL luôn ở mức cao (có điện trở kéo lên)

#### Các bước truyền dữ liệu

![image](https://github.com/KhanhTruongTG/EMBEDDED-INTERVIEW-T7/assets/139245069/33ab07c6-4794-4306-9136-fc3d2563d718)
```sh
Ghi chú:
  - Màu xám: Master
  - Màu trắng: Slave
```

  - Master gửi điều kiện khởi động đến mọi Slave được kết nối bằng cách chuyển đường SDA từ mức điện áp cao sang mức điện áp thấp trước khi chuyển đường SCL từ mức cao xuống mức thấp
  - Master gửi cho mỗi Slave địa chỉ 7 hoặc 10 bit của Slave mà nó muốn giao tiếp, cùng với bit đọc/ghi (thường là 7 bit + 1 bit đọc/ghi). Khung địa chỉ bao gồm một bit duy nhất ở cuối tin nhắn cho Slave biết Master muốn ghi dữ liệu vào nó hay nhận dữ liệu từ nó
    + Nếu Master muốn gửi dữ liệu đến Slave, bit đọc/ghi ở mức điện áp thấp
    + Nếu Master đang yêu cầu dữ liệu từ Slave, thì bit đọc/ghi ở mức điện áp cao
  - Mỗi Slave sẽ so sánh địa chỉ được gửi từ master với địa chỉ của chính nó.
    + Nếu địa chỉ trùng khớp, Slave sẽ trả về một bit ACK bằng cách kéo dòng SDA xuống thấp cho một bit
    + Nếu địa chỉ từ Master không khớp với địa chỉ của Slave, Slave rời khỏi đường SDA cao
  - Master gửi hoặc nhận khung dữ liệu
  - Sau khi mỗi khung dữ liệu được chuyển, thiết bị nhận trả về một bit ACK khác cho thiết bị gửi để xác nhận đã nhận thành công khung
  - Để dừng truyền dữ liệu, Master gửi điều kiện dừng đến Slave bằng cách chuyển đổi mức cao SCL trước khi chuyển mức cao SDA

</details>

<details> <summary> INTERRUPT </summary>


</details>

<details> <summary> TIMER </summary>


</details>

<details> <summary> CAN </summary>


</details>














