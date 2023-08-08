#include <stdio.h>
#define MAX 1000

void reverse(char* str){
    int length = 0;                 //chiều dài chuỗi
    int i = 0;                      //vị trí đầu trong từ (trái)
    int j = 0;                      //vị trí cuối trong từ (phải)
  
    //chuỗi ví dụ string[]="dao ki tu"
    //đếm chiều dài chuỗi
    while(str[length] != '\0'){
        length++;
    }

    //đảo từng từ trong chuỗi
    while(j <= length){                   
        if(str[j] == ' ' || str[j] == '\0'){
            int left = i;                       //gán left là vị trí đầu của từ 
            int right = j - 1;                  //gán right là vị trí cuối của từ 
            while(left < right){
                char temp = str[left];
                str[left] = str[right];
                str[right] = temp;              
                left++;                         
                right--;                        
            }
            i = j + 1;              //lấy kí tự sau dấu cách  
        }
        j++; 
    }                               //kết quả: oad ik ut

    //đảo vị trí của toàn chuỗi (oad ik ut)
    int left1 = 0;                              //gán left1 là vị trí đầu của chuỗi                           
    int right1 = length - 1;                    //gán right1 là vị trí cuối của chuỗi         
    while(left1 < right1){            
        char temp = str[left1];         
        str[left1] = str[right1];
        str[right1] = temp;
        left1++;
        right1--;
    }
}                                   //kết quả: tu ki dao

int main(){
    char string[MAX];
    printf("nhap string: ");
    gets(string);

    reverse(string);
    printf("string sau khi dao: %s\n", string);
    return 0;
}
