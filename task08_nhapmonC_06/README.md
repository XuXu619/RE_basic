## Tiem hiểu về file trong C
> Tài liệu tham khảo: 
> 
> Thực hiện: **XuXu**
> 
> Cập nhật lần cuối: **19/3/2018**
> 

### Mục lục 

[1. Thao tác với File trong C](#thaotacvoifile)

-	[1.1 Mở File](#mofile)

-	[1.2 Đóng File](#dòngile) 

-	[1.3 Ghi tới một File trong C](#ghi)

-	[1.4 Đọc File trong C](#docfile)
 
-	[1.5 Các hàm xuất nhập ngẫu nhiên](#ham)

-	[1.6 Tổng kết các hàm tương tác với File](#all)

[2. Lưu trữ dữ liệu và tổ chức bộ nhớ](#luutrudulieu)

-	[2.1 Bộ nhớ chương trình](#bonho) 

-	[2.2 Các từ khóa thường dùng](#tukhoa) 


<a name="thaotacvoifiletrongc">

###1. Thao tác với file trong C

* Một file biểu diễn một chuỗi các bytes, không kể đó là fije văn bản hay file nhị phân. Ngôn ngữ lập trình C cung cấp các hàm truy cập mức độc cao cũng như thấp (mức hệ điều hành) để thao tác với file trên thiết bị lưu trữ. Chương này sẽ đưa bạn tới các cách gọi hàm quan trọng cho việc quản lí file.

#### 1.1 Mở file:

* Bạn có thể sẻ dụng hàm fopen() để tạo file mới hoặc để mở các file đã tồn tại. Cách gọi này sẽ khởi tạo đối tường loại FILE mà bao gồm thông tin cần thiết để điều khiển. Dưới đây là một cách gọi làm:

	File *fopen( const char * ten+file, const char * che_do);

* Ở đây ten_file là một chuỗi, được coi như tên file và giá trị che_do truy caasoj cí thể là những giá trị dưới đây:

* Nếu bạn thao tác với các file nhị phân, bạn có thể có cách truy xuất thay cho các trường hợp trên sau:

* "rb", "wb", "ab", "rb+", "r+b", "w+b", "ab+", "a+b"

#### 1.2 Đóng File

* ĐÓng file trong C 

* Để đóng một file bạn có thể sẻ dụng hàm fclose() dưới đây:

	int close( FILE *fp)

* Hàm fclose() trả về gía trị zero nếu thành công hoặc EOF nếu có lỗi trong qúa trình đóng file. Hàm này thực tế cóa các dữ liệu trong bộ đệm đối với file, đóng file và giải phóng vộ nhớ được sử dụng với file. EOF là một hằng số được điịnh nghĩa trong thư viện stdio.h.

* Có nhiều hàm đa dạng được cung cấp bởi thư viện chuẩn của ngôn ngữ C để đọc và ghi từng kí tự và trong một dạng với số lượng tự cố định.

#### 1.3 Ghi tới một file trong C

* Dưới đây là hàm đơn giản nhất để thực hiện việc ghi các kí tự riêng tới một luồng:

	int fputc( int c. FILE *fp );

* Hàm fputo() ghi các kí tự với giá trị tham số c đến một luồng ra tham chiếu bởi con trỏ fp. Nó sẽ trả về kí tự được ghi nếu thành công hoặc ÈOF nesu có lỗi. Bạn có thể sẻ dụng hà sau đây để ghi một chuỗi kết thúc bằng kí tự null đến một luồng:

	int fputs( const chả *s, FILE *fp);

* Hàm fputs() hi chuỗi s dến một luồng ra tham chiếu bởi fp. Nó trả về một giá trị không âm neesi thành công và trả về kí tự EOF nếu xảy ra lỗi. Bạn có thể sử dụng hàm int fprintf(FILE *fp, const char *format, ...) để ghi một chuỗi ra file. Thử ví dụ dưới đâu: 

* Bạn phải chắc chán bạn có thư mục /tmp, nếu không có bạn phải tạo thư mục này trên máy bạn.

```c #include<stdio.h>
main()
{
FIle *fp;
fp = fopen("vidu.txt", "w+");
fprintf(fp, "Vi du kiem tra ham fprintf ... /n");
fputs(fp);
}
```

* Khi đoạn code trên được biên dịch và thực hiện, nó tạo file mới là vidu.txt và ghi vào đó hai dòng của hai hàm khác nhau 

####1.4 Đọc file trong C

* Dưới đây là ham đơn giản nhất để đọc một kí tự riêng rẽ từ file:

	int fgets(FIle *fp)

* hàm fgets() đọc một kí tự từ một file tham chiếu boeir con trỏ fp. GIá trị trả về là  kí tự đọc được nếu thành công và trường hợp lỗi sẽ trả về EOF. Hàm dưới đây cho phép bạn đọc chuỗi từ một luồng :

	char *fgets (char *buf, int n, FILE *fp);

* Hàm fgets() đọc n - 1 kí tự từ một luồng vào tham chiếu bởi fp. Nó copy chuỗi đọc đến bộ đệm buf, gán kí tự null vào kết thúc chuỗi.

* Nếu hàm gặp phải một kí tự newline .n hoặc EOF trước khi đọc được số lượng tối đa các kí tự, nó sẽ chỉ trả về kí tự cho đến ký tự cuống dòng và kí tự cuống dòng mới, Bạn có thể sử dụng hàm int fscanf(FILE *fp, const char *format, ...) để đọc chuỗi từ một file, nhưng dừng biệc đọc ở khoảng trắng đầu tiên gặp phải:

```c #include<stdio.h>
main()
{
FILE *fp;
char buff[225];

fp = fopen(" vidu.txt", "r" );
fscanf(fp, "%s", buff);
printf("1 : %s\n", buff);

fgets(buff, 255, (FILE*)fp);
printf("2: %s")\n", buff );

fgets(buff, 255, (FILE*)fp);
printf("3: %s\n", buff);
fclose(fp);

}
```

Biên dịch và chạy chương trình C trên, đầu tiên nó đọc từ file được tạo từ khu vực trước và in kết quả.

* Cùng xem một chút chi tiêt hơn về điều xảy ra ở đây. Đầu tiên `fscanf()` chỉ đọc This bởi vì sau đó nó gặp phải dấu cách, tiếp theo hàm `fgets()` trả về các dòng còn lại cho đến khi gặp kí tự cuối file. Cuối cùng nó gọi hàm `fgets()` để đọc hoàn toàn dòng thứ 2.

#### 1.5 Các hàm xuất nhập ngẫu nhiên và di chuyển con trọ chỉ vị:

* Khi tệp tin để đọc hay ghi, con trỏ chir vị luôn luôn ở đầu tập tin (byte 0 ) nếu mở mode "a" (append) => con trỏ chỉ vị ở cuối tập tin.
  * Hàm void rewind(FILE*ip): Chuyển con trỏ chỉ vị của tập fp về đầu tập tin.
  * Hàm int dseek (FILE*fp, long số byte, int xp)

* Đối : fp là con trỏ tập tin, số byte là số byte cần di chuyển.

  * xp " cho biết vị trí xuất phát mà việc dịch chuyển được bắt đầu từ đó.
  * xp = SEEK-SET hay 0 xuất phát từ đầu tập.
  * xp = SEEK - CỦ hay 1: xuất phát từ vị trí hiện tại của con trỏ.
  * xp = SEEK - END hay 2: xuất phát từ vị tí cuối tập của con trỏ.

* Công dụng: Hàm di chuyên con trỏ chỉ vị của tjp fp từ vị trí xác định với xp qua một số byte bằng giá trị tuyệt đối của số byte. Nếu số byte >  0 : chuyển về hướng cuối tập ngược lại chuyển về hướng đầu tập. Nếu thành công trả về giá trị 0 neeus có lỗi trả khác 0 

* Chú ý không nên dùng fseep trên kiểu văn bản, vì sự chuyển đối kí tự ( mac 10) ẽ làm cho việc định vị thiếu chính xác.

* Hàm long ftell(FILE*fp): cho biết vị trí hiện tại của con trỏ chỉ vị (byte thứ nấy trên tập fp) nếu không thành công trả về giá trị -1L.

* Ví dụ 1: giả sử tập fp có 3 ksi tự.

	fseek (fp, 0, SEEK - END) = > ftell(fp) = 3 

        fseek(fp,0,2) => ftell(fp) = 3

        fseek (fp,-2, SEEK-END) => ftell(fp) = 1

        fseek(fp,0,SEEK -SET) => ftell(fp) = 0

        fseek(fp,0, 0) =>ftell(fp) = 0

* Ví dụ 1 : giả sử ta có tập tin c:\lop.txt chứa danh sách các học viên. Hãy đọc danh sách và sắp xếp giảm dần theo điểm sau đó ghi lại file c:\lop.txt ( nối điểm)

```c #include <stdio.h>
#include<conio.h>
#include<string.h>
#define N 100
typedef struct
{ char ten[20] ; int tuoi; float diem ; } KieuHV ;
void main( )
{ KieuHV hv[N] ; t;
FILE*fp ; int i, , n ;
fp = fopen ("c:\\lop.txt ", "rat");
if (fp = =NULL)
   { printf ("không mở được file "); exit(1); }
       n = 0 ; i = 0 ;
     while (!feof (fp))
         { fread (&hv[i], size of (KieuHV), 1,fp);
             i++; n++ ;
  /* sắp xếp giảm dần theo điểm */
       for (i=0, i <n-1, i++)
       for (j=i+1; j<n, j++)
            if (hv[i].diem <hv[j].diem)
                { t =hv[i] ; hv[i] = hv[j] ; hv[j] = t }
/* ghi lên đĩa */
fseek (fp, 0, SEEK-END);
for ( i=0; i<n ; i++)
fwrite(&hv[i], size of (KieuHV), 1, fp);
}
```

####1.5 Tổng kết các hàm tương tác với C:

* fopen : Dùng để mở tệp. Trước khi làm việc với tệp cần phải mở nó
* fclose: Dùng để đóng tệp. Cần đống tệp trước khi kết thúc chương trình hay khi không làm việc với tệp nữa
* fcloseall: Dùng để đống tất cả các tệp đang mở
* fflush : Dùng để làm sạch vùng đệm của tệp
* fflushall: Dùng để làm sạch vùng nhớ đệm của các tệp đang mở
* ferror : Cho biết có lỗi (khác 0) hay không lỗi (bằng 0)
* perror : Thông báo lỗi trên màn hình (khi biết có lỗi)
* feof : Cho biết đã gặp cuối tệp hay chưa
* unlink và remove : Dùng để loại tệp trên đĩa
* rewind : Dùng để chuyển con trỏ chỉ vị về đầu tệp.
* fseek : Dùng để di chuỷen cin trỏ chỉ vị đến vị trí bất kỳ trên tệp (hàm này chỉ nên dùng theo kiểu nhị phân).
* ftell : Cho biết vị trí hiện tại của con trỏ chỉ vị

Các hàm nhập xuất ký tự

* putc và fputc : Dùng để ghi ký tự lên tệp.
* getc và fgetc : Dùng để đọc ký tự từ tệp.

Các hàm nhập xuất theo kiểu văn bản

* fprintf : Dùng để ghi dữ liệu theo khuôn dạng lên tệp
* fscanf : Dùng để đọc dữ liệu từ tệp theo khuôn dạng
* fputs : Dùng để ghi một chuỗi ký tự lên tệp
* fgcts : Dùng để đọc một dãy ký tự từ tệp

Các hàm nhập xuất theo kiểu nhị phân

* putw : Dùng để ghi một số nuyên (2 byte) lên tệp
* getw : Dùng để độc một số nguyên (2 byte) từ tệp
* fwritc : Dùng để ghi một số mẫu tin lên tệp
* fread : Dùng để độc một số mẫu tin từ tệp

###2. Lưu trữ dữ liệu và tổ chức bộ nhớ chương trình:

* Như đã biết trước khi sử dụng một đối tượng dữ liệu (biến, mảng, cấu trúc, union,...), thì cần phải khi báo nó.

* Vị trí khai báo (bên trong hoặc bên ngoài hàm) quyết định hai vấn đề then chốt sau đây:

  * Đối tượng dữ liệu được lưu giữ trong phần cố định (vùng cấp phát tĩnh) hay phần tạm thời (vùng ngăn xếp) của bộ nhớ chương trình

  * Phạm vi sử dụng của đối tượng dữ liệu là cục bộ (bên trong một khối, một hàm) hay toàn bộ (từ vị trí khai báo đến cuối tệp tin của chương trình).

####2.1 Bộ nhớ chương trình:

* Bộ nhớ chương trình được chia ra làm 4 phần là (theo thứ tự từ địa chr thấp đến địa chỉ cao)
        Vùng mã lệnh (chứa mã lệnh và hằng).
        Vùng cấp phát tĩnh (chứa các đối tượng ngoài và tĩnh).
        Vùng cấp phát động (heap)
        Vùng ngăn xếp (chứa các đối tượng cục bộ).

* Hai vùng đầu có độ lớn cố định trong suốt thời gian chương trình làm việc.

* Vùng cấp phát động lưu trữ các đối tượng (biến, mảng, cấu trúc, ...) được cấp phát bằng hàm malloc. Vì vập mỗi khi thực hiện hàm này, thì vùng heap được nở ra. Ngược lại khi thực hiện hàm free (để giải phóng một vùng nhớ trên heap), thì không gian sử dụng trên heap bị thu lại.

* Vùng ngăn xếp dùng để lưu trữ các đối tượng cục bộ. Mỗi khi chương trình thực hiện một khối lệnh hoặc một hàm, thì các đối tượng khai báo trong khối hàm đó được lưu trữ trên ngăn xếp và ngăn xếp phình ra. Khi chương trihf ra khổi một hàm hay một khối lệnh, thì các đối tượng cục bộ của hàm hay khối đó bị lấy ra khỏi ngăn xếp, và ngăn xếp bị thu nhỏ lại.

* Như vậy độ lớn sử dụng của vùng heap và ngăn xếp luôn thay đổi trong thời gian chương trình làm việc

####2.2 Các từ khoá thường dùng:

Từ khoá auto

* Từ khoá auto đặt trước một khai báo biến bên trong hàm để chỉ rõ tính cục bộ của các đối tượng được khai báo. Vì các biến khai báo trong một hàm đương nhiên là cục bộ, nên từ khoá này là không cần thiết và rất ít được dùng.

Biến ngoài và từ khoá Extern

* Biến cục bộ: Biến khai báo bên trong một hàm hoặc một khối là biến cục bộ. Nó được lưu trữ trong ngăn xếp khi chương trinh xét đến hàm hoặc khối chứa nó. Khi chưa được khởi đầu thì giá trị của biến cục bộ là chương xác định.

* Biến ngoài: Biến khai báo bên ngoài các hàm gọi là biến ngoài hay biến toàn bộ. Nó có một địa chỉ cố định (tại vùng cấp phát tĩnh) trong suất thời gian chương trình làm việc. Khi chưa được khởi đầu thì giá trị của toàn bộ bằng không. Nó có thể sử dụng cho các tệp khác (khi chương trình gồm nhiều tệp) nhời khai báo extern viết trên các tệp này.

* Extern:

  * Sử dụng khi một chương trinhg viết trên nhều tệp và các tệp này được dịch độc lập sau đó mới liên kết với nhau tao thành tệp chương trình khả thi (.exe).

  * Vị tri khai báo:
            Có thể ngoài các hàm.
            Có thể bên trong một hàm hoặc một khối lệnh.

  * Phạm vi sử dụng: Dùng khai báo ửo đâu thì phạm vi sử dụng của biến extern (trên tệp chứa khai báo này) được tính từ vị trí khai báo cho đến cuối tệp. Rõ ràng đây là điều khác thường sao với những gì đã nói về phạm vi sử dụng của một biến.

Từ khoá Static

* Từ khoá static dùng để khai báo các biến tĩnh trong (cục bộ) và các biến tĩnh ngoài (toàn bộ).

Từ khoá register

* Từ khoá register có thể dùng để khai báo các biến toàn cục và các đối kiểu int hoặc char theo mẫu:

```c register int i, j;
register char ch;
```

* Các biến regis ter được lưu trữ trong các thanh ghi SI hoặc DI nếu có thể. Khi các thanh ghi này bận thì các biến register được lưu trữ và ngăn xếp như các biến cục bộ thông thường.
    
* Biến register thường được sử dụng làm biến điều khiển để tăng tốc độ thực hiện cảu các vòng lập. 


Ví dụ trong hàm tính xn ta đưa vào đối register n như sau:

```c double pow(double x, register  int n)
{
	double s=1.0;
	for (;n; --n) s*= x; return x;
}
```

* Chú ý : Ta có thể kai báo nhiều biến register nhưng không quá 2 trong chúng được lưu trữ trong các thanh ghi.

Từ khoá Const

* Từ khoá Const có hai tác dụng:

  * Dùng để khai báo và khởi đầu giá trị cho các biến trong và biến ngoài mà sau ngày giá trị của nó không cho phép thay đổi bởi các lệnh trong chương trình. Ta gọi chúng là các đối tượng hằng
        
  * Dùng để khai báo các đối con trỏ mà trong thân hàm ta không được phép làm thay đổi giá trị các đối tượng được trỏ tới bởi các đối này.

Từ khoá volatile

* Khi khai báo 

	volatile int t_time;

Dùng đẻ báo cho trình dịch biết g

        fseek(fp,0,2) => ftell(fp) = 3

        fseek (fp,-2, SEEK-END) => ftell(fp) = 1

        fseek(fp,0,SEEK -SET) => ftell(fp) = 0

        fseek(fp,0, 0) =>ftell(fp) = 0

* Ví dụ 1 : giả sử ta có tập tin c:\lop.txt chứa danh sách các học viên. Hãy đọc danh sách và sắp xếp giảm dần theo điểm sau đó ghi lại file c:\lop.txt ( nối điểm)

```c #include <stdio.h>
#include<conio.h>
#include<string.h>
#define N 100
typedef struct
{ char ten[20] ; int tuoi; float diem ; } KieuHV ;
void main( )
{ KieuHV hv[N] ; t;
FILE*fp ; int i, , n ;
fp = fopen ("c:\\lop.txt ", "rat");
if (fp = =NULL)
   { printf ("không mở được file "); exit(1); }
       n = 0 ; i = 0 ;
     while (!feof (fp))
         { fread (&hv[i], size of (KieuHV), 1,fp);
             i++; n++ ;
  /* sắp xếp giảm dần theo điểm */
       for (i=0, i <n-1, i++)
       for (j=i+1; j<n, j++)
            if (hv[i].diem <hv[j].diem)
                { t =hv[i] ; hv[i] = hv[j] ; hv[j] = t }
/* ghi lên đĩa */
fseek (fp, 0, SEEK-END);
for ( i=0; i<n ; i++)
fwrite(&hv[i], size of (KieuHV), 1, fp);

}
```

####1.5 Tổng kết các hàm tương tác với C:

* fopen : Dùng để mở tệp. Trước khi làm việc với tệp cần phải mở nó
* fclose: Dùng để đóng tệp. Cần đống tệp trước khi kết thúc chương trình hay khi không làm việc với tệp nữa
* fcloseall: Dùng để đống tất cả các tệp đang mở
* fflush : Dùng để làm sạch vùng đệm của tệp
* fflushall: Dùng để làm sạch vùng nhớ đệm của các tệp đang mở
* ferror : Cho biết có lỗi (khác 0) hay không lỗi (bằng 0)
* perror : Thông báo lỗi trên màn hình (khi biết có lỗi)
* feof : Cho biết đã gặp cuối tệp hay chưa
* unlink và remove : Dùng để loại tệp trên đĩa
* rewind : Dùng để chuyển con trỏ chỉ vị về đầu tệp.
* fseek : Dùng để di chuỷen cin trỏ chỉ vị đến vị trí bất kỳ trên tệp (hàm này chỉ nên dùng theo kiểu nhị phân).
* ftell : Cho biết vị trí hiện tại của con trỏ chỉ vị

Các hàm nhập xuất ký tự

* putc và fputc : Dùng để ghi ký tự lên tệp.
* getc và fgetc : Dùng để đọc ký tự từ tệp.

Các hàm nhập xuất theo kiểu văn bản

* fprintf : Dùng để ghi dữ liệu theo khuôn dạng lên tệp
* fscanf : Dùng để đọc dữ liệu từ tệp theo khuôn dạng
* fputs : Dùng để ghi một chuỗi ký tự lên tệp
* fgcts : Dùng để đọc một dãy ký tự từ tệp

Các hàm nhập xuất theo kiểu nhị phân

* putw : Dùng để ghi một số nuyên (2 byte) lên tệp
* getw : Dùng để độc một số nguyên (2 byte) từ tệp
* fwritc : Dùng để ghi một số mẫu tin lên tệp
* fread : Dùng để độc một số mẫu tin từ tệp

###2. Lưu trữ dữ liệu và tổ chức bộ nhớ chương trình:

* Như đã biết trước khi sử dụng một đối tượng dữ liệu (biến, mảng, cấu trúc, union,...), thì cần phải khi báo nó.

* Vị trí khai báo (bên trong hoặc bên ngoài hàm) quyết định hai vấn đề then chốt sau đây:

  * Đối tượng dữ liệu được lưu giữ trong phần cố định (vùng cấp phát tĩnh) hay phần tạm thời (vùng ngăn xếp) của bộ nhớ chương trình

  * Phạm vi sử dụng của đối tượng dữ liệu là cục bộ (bên trong một khối, một hàm) hay toàn bộ (từ vị trí khai báo đến cuối tệp tin của chương trình).

####2.1 Bộ nhớ chương trình:

* Bộ nhớ chương trình được chia ra làm 4 phần là (theo thứ tự từ địa chr thấp đến địa chỉ cao)
	Vùng mã lệnh (chứa mã lệnh và hằng).
        Vùng cấp phát tĩnh (chứa các đối tượng ngoài và tĩnh).
        Vùng cấp phát động (heap)
        Vùng ngăn xếp (chứa các đối tượng cục bộ).

* Hai vùng đầu có độ lớn cố định trong suốt thời gian chương trình làm việc.

* Vùng cấp phát động lưu trữ các đối tượng (biến, mảng, cấu trúc, ...) được cấp phát bằng hàm malloc. Vì vập mỗi khi thực hiện hàm này, thì vùng heap được nở ra. Ngược lại khi thực hiện hàm free (để giải phóng một vùng nhớ trên heap), thì không gian sử dụng trên heap bị thu lại.

* Vùng ngăn xếp dùng để lưu trữ các đối tượng cục bộ. Mỗi khi chương trình thực hiện một khối lệnh hoặc một hàm, thì các đối tượng khai báo trong khối hàm đó được lưu trữ trên ngăn xếp và ngăn xếp phình ra. Khi chương trihf ra khổi một hàm hay một khối lệnh, thì các đối tượng cục bộ của hàm hay khối đó bị lấy ra khỏi ngăn xếp, và ngăn xếp bị thu nhỏ lại.

* Như vậy độ lớn sử dụng của vùng heap và ngăn xếp luôn thay đổi trong thời gian chương trình làm việc

####2.2 Các từ khoá thường dùng:

Từ khoá auto

* Từ khoá auto đặt trước một khai báo biến bên trong hàm để chỉ rõ tính cục bộ của các đối tượng được khai báo. Vì các biến khai báo trong một hàm đương nhiên là cục bộ, nên từ khoá này là không cần thiết và rất ít được dùng.

Biến ngoài và từ khoá Extern

* Biến cục bộ: Biến khai báo bên trong một hàm hoặc một khối là biến cục bộ. Nó được lưu trữ trong ngăn xếp khi chương trinh xét đến hàm hoặc khối chứa nó. Khi chưa được khởi đầu thì giá trị của biến cục bộ là chương xác định.

* Biến ngoài: Biến khai báo bên ngoài các hàm gọi là biến ngoài hay biến toàn bộ. Nó có một địa chỉ cố định (tại vùng cấp phát tĩnh) trong suất thời gian chương trình làm việc. Khi chưa được khởi đầu thì giá trị của toàn bộ bằng không. Nó có thể sử dụng cho các tệp khác (khi chương trình gồm nhiều tệp) nhời khai báo extern viết trên các tệp này.

* Extern:

  * Sử dụng khi một chương trinhg viết trên nhều tệp và các tệp này được dịch độc lập sau đó mới liên kết với nhau tao thành tệp chương trình khả thi (.exe).

  * Vị tri khai báo:
            Có thể ngoài các hàm.
            Có thể bên trong một hàm hoặc một khối lệnh.

  * Phạm vi sử dụng: Dùng khai báo ửo đâu thì phạm vi sử dụng của biến extern (trên tệp chứa khai báo này) được tính từ vị trí khai báo cho đến cuối tệp. Rõ ràng đây là điều khác thường sao với những gì đã nói về phạm vi sử dụng của một biến.

Từ khoá Static

* Từ khoá static dùng để khai báo các biến tĩnh trong (cục bộ) và các biến tĩnh ngoài (toàn bộ).

Từ khoá register

* Từ khoá register có thể dùng để khai báo các biến toàn cục và các đối kiểu int hoặc char theo mẫu:

	register int i, j;
	register char ch;

* Các biến regis ter được lưu trữ trong các thanh ghi SI hoặc DI nếu có thể. Khi các thanh ghi này bận thì các biến register được lưu trữ và ngăn xếp như các biến cục bộ thông thường.
    Biến register thường được sử dụng làm biến điều khiển để tăng tốc độ thực hiện cảu các vòng lập. Ví dụ trong hàm tính xn ta đưa vào đối register n như sau:

```c double pow(double x, register  int n)
{
	double s=1.0;
	for (;n; --n) s*= x; return x;
}
```

* Chú ý : Ta có thể kai báo nhiều biến register nhưng không quá 2 trong chúng được lưu trữ trong các thanh ghi.

Từ khoá Const

* Từ khoá Const có hai tác dụng:

  * Dùng để khai báo và khởi đầu giá trị cho các biến trong và biến ngoài mà sau ngày giá trị của nó không cho phép thay đổi bởi các lệnh trong chương trình. Ta gọi chúng là các đối tượng hằng
        
  * Dùng để khai báo các đối con trỏ mà trong thân hàm ta không được phép làm thay đổi giá trị các đối tượng được trỏ tới bởi các đối này.

Từ khoá volatile


	volatile int t_time;

* Dùng đẻ báo cho trình dịch biết giá trị của biến nguyên t_time có thể bị thay đổi theo một cách nào đó không được mô tả rõ trong chương trình, chẳng hạn t_time có thể thay đổi bởi các ngắt của DOS hay ROM BIOS. Biến volatile thường là các biến toàn bộ dùng để trong các thủ tục ngắt.


    

    

 
