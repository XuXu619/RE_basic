## Con trỏ (tiếp theo)

> Tài liệu tham khảo:  http://bit.ly/2eFUang
>
> Người thực hiện: XuXu
>
> Thực hiện lần cuối: **10/03/2017**
>

### Menu

[1. Kiểu cấu trúc struct, enum](#struct)

[2. Cấu trúc con trỏ](#cautruc)

[3. Hàm trên các cấu trúc](#ham) 

[4. Danh sách liên kết ( 1 chiều, 2 chiều)](#danhsachlienket) 

[5. Sử dụng cấp phát tĩnh và động ](#capphat)


<a name="kieucautrucstruct,enum"></a>

### 1. Kiểu cấu trúc struct, enum 


Để lưu trữ và xử lý thông tin trong máy tính ta có các biến và các mảng. Mỗi biến chứa một giá trị. Mảng có thẻ xem là tập hợp nhiều biến có cùng một kiểu giá trị và được biểu thị bằng một cái tên. Cấu trúc có thể xem như một sự mở rộng của các khái niệm biến và mảng, nó cho phép lưu trữ và xử lý các dạng thông tin phức tập hơn, Cấu trúc là một tập hợp các biến, các mảng và được biểu thị bởi một tên duy nhất. Khái niệm cấu trúc trong C có những nét tương tự như khái niệm bản ghi (record) trong Pascal hay Foxpro. Một ví dụ truyền thống về cấu trúc là phiếu ghi lương: Mỗi công nhân được miêu tả bởi một tập hợp các thuộc tính như tên, địa chỉ, ngày sinh, bật lương, ... Một vài trong thuộc này lại có thẻ là cấu trúc: Tên có thể có nhiều thành phần, địa chỉ và thậm chí ngày sinh cũng vậy.

1.1 Định nghĩa và khai báo


 - Định nghĩa: Dữ liệu cấu trúc là một kiểu dữ liệu bao gồm nhiều thành phần có kiểu khác nhau, mỗi thành phân được gọi là một trường (field)</ul> 


 - Về mặt ngữ pháp điều này hoàn toàn giống như việc khai báo các biến và các mảng. Khi kgai báo một biến cần chỉ ra kiểu và tên của nó.</ul> 


 - Kiểu cấu trúc khác mảng ở chỗ: Các phần tử của mảng có cùng kiểu, trong khi các phần tử của cấu trúc có nhiều kiểu khác nhau. Như thws, một cấu trúc đơn giản có thể chứa các phần tử nguyên, các phần tử chấm động và các phần tử kí tự. Con trỏ, mảng và những kiểu cấu trúc khác cũng có thể được bao gồm như là những phần tử bên trong một cấu trúc.</ul> 

 - Khai báo biến: Cú pháp `struct< tên cấu trúc >< biến1 >< biến 2 > ....;`</li>


 - Ví dụ khai báo:</ul> 

        float x, y;

Cho ta hai biến kiểu float với các tên là x và y. Ta cũng sẽ làm y hệt như vậy khi khai báo biến cấu trúc. Giả sử ta đã có ác kiểu cấu trúc ngay va nhan_cong như trong các ví dụ 1.1 và 1.2 khi đó ta có thể xét các ví dụ sau:

 - Ví dụ 2.1 : Khai báo</ul> 
       `struct ngay ngay_di, ngay_den;`

Sẽ cho ta hai biến cấu trúc với tên là ngay_di và ngay_den. Cả hai đều được xây dựng theo kiểu ngay.

 - Ví dụ 2.2 : Khai báo</l>
        `struct nhan_cong, nguoi_a, nguoi_b;` 

Sẽ cho ta hai cáu trúc với tên là nguoi_a và nguoi_b. Cả hai đều được xây dựng theo kieu nhan_cong

Một cách tổng quát, việc khai báo cấu trúc được thực hiện theo mẫu:

    `struct tên_kiểu_cấu_trúc danh_sách_tên_cấu_trúc;`

 - Sau đây là một vài điều cần lưu ý:
<ul> 

 - Nhận xét 2.1: Các biến cấu trúc được khai báo theo mẫu trên sẽ được cấp phát bộ nhớ một cách đầy đủ cho tất cả các thành phàn của nó.</ul> 

 - Nhận xét 2.2: Việc khai báo có thể thực hiện đồng thời với việc dịnh nghĩa kiểu cấu trúc. Muốn vậy chỉ cần đặt danh sách tên biến cấu trúc cần khai báo vào sau } cuối cùng trong mẫu 1.1</ul> 

Nói cách khác: Đề vừa thiết kế kiểu vừa khai báo các biến cấu trúc ta sử dụng mẫu sau:

Mẫu 2.2

 ```c struct ten_kiểu_cấu_trúc 
{
	các thành phần cảu cấu trúc
} danh sách tên biến cấu trúc
```

 - Ví dụ 2.3: Các cấu trúc ngay_di và ngay_den trong ví dụ 2.1 có thể được xây dựng theo cách:</ul>


```c struct ngay
{
	int ngay_thu;
	char ten_thang[10];
	int nam;
} ngay_di, ngay_den;
``` 

 - Ví dụ 2.4: Các cấu trúc nguoi_a, nguoi_b trong ví dụ 2.2 có thể xây dựng theo mẫu sau (giải sử kiểu ngay đẫ được mô tả như ở ví dụ 1.1)</ul>


``` C++ struct nhan_cong
{
	char ten[15];
	char dia_chi[20];
	double bac_luong;
	struct ngay ngay_sinhl
	struct ngay ngay_vao_co_quan;
} nguoi_a, nguoi_b;
```

 - Nhận xét 2.3 : Khi vừa định nghĩa kiểu (cấu trúc) vừa khai báo cấu trúc như trong ví dụ 2.3 và 2.4 ta có thể không cần đến tên kiểu cấu trúc. Nói cách khác các cấu trúc có thể được khai báo theo mẫu sau.</ul> 

Mẫu 2.3 :

```c struct
{
	các thành phần cảu cấu trúc
} danh sách tên cấu trúc;
```


 - Ví dụ 2.5: Các cấu trúc `ngay_di và ngay_den` trong ví dụ 2.3 được khai báo theo cách:</ul>


```c struct
{
	int ngay_thu;
	char ten_thang[10];
	int nam;
} ngay_di, ngay_den;
``` 



 - Cũng cần nói thêm sự khác nhau giữa mẫu 2.2 và mẫu 2.3. Điều ngày sẽ trở nên hoàn toàn rõ ràng khi so sánh ví dụ 2.3 và ví dụ 2.5 ở ví dụ 2.3 ngoài việc xây dựng được cấcc cấu trúc ngay_di, ngay_den ta còn cho ra đời được kiểu cấu trúc ngay. Kieẻu ngay có thể sử dụng để khai báo ở các cấu trúc khác. Ỏ ví dụ 2.4 ta chỉ đặt được mục đích đầu của ví dụ 2.3.</ul> 


 - Chú ý: Nếu dùng typedef để định nghĩa kiểu cấu trúc, thì khi khai báo ta chỉ cần dùng tên kiểu (bỏ từ khoá struct). Ví dụ như kiểu cấu trúc ngay dược định như trong chú ý 1.1 của 2.1 thì các cấu trúc ngay_di và ngay_den trong ví dụ 2.1 có thể khai báo như sau:</li>  


`ngay ngay_di, ngay_den;`


 - Truy xuất các trường của cấu trúc
</ul> 

- Mẫu 3.1: </li>

```c tên_cấu_trúc.tên_thành_phần
tên_cấu_trúc.tên_cấu_trúc.tên_thành_phần
tên_cấu_trúc.tên cấu trúc.tên_cấu_trúc.tên_thành_phần
...
``` 

- Các viết thứ nhất của mẫu 3.1 được sử dụng khi biến haowjc mảng là thnahf phần trực tiếp của một cấu trúc. Ví dụ biến ngay_thu, bién nam và mảng ten_thang là các thành phần trực tiếp của cấu trúc ngay_di (xem ví dụ 2.3). Mảng ten, mảng di_chi và biến bac_luong là các thành phần trực tiếp của cấu trúc nguoi_b (xem ví dụ 2.4). Các cách viết còn lại của mẫu 3.1 được sử dụng khi biến hoặc mảng là thành phần trực tiếp của một cauá tryúc mà bản thân cấu trúc này lại là thành phần của một cấu trúc lớn hơn. 
</ul> 

- Ví dụ 3.1 Ta xét vài phép toán trên các thành phần của cấu trúc nguoi_a và nguoi_b (xem ví dụ 2.4).</ul> 

- Câu lệnh:</ul> 

	printf("%s",nguoi_a.ten);

sẽ đưa tên của nguoi_a lên màn hình.

- Khi thực hiện câu lệnh:</ul>


	s = nguoi_a.bac_luong + nguoi_b.bac_luong;


Thì biến s sẽ nhận được tổng bậc lương của nguoi_a và nguoi_b;

- Câu lệnh: </ul> 

	printf("%d",nguoi_a.ngay_sinh.nam);

sẽ cho lên màn hình năm sinh của nguoi_a.

- Câu lệnh:</ul>


	printf("%d",nguoi_b.ngay_vao_co_quan.nam);


sẽ cho lên màn hình năm vào cơ qua của nguoi_b.


- Chú ý 3.1 Có thể sử dụng phép toán lấy địa chỉ đối với thành phần cấu trúc để nhập số liệu trực tiếp vào thành phần cấu trúc. Ví dụ:
</ul>


`scanf("%d",&nguoi_b.ngay_vao_co_quan.nam);`


- Nhưng đối với các thành phần không nguyên , việc làm trên có thể dẫn đến treo máy. Ví vậy trước tiên nên nhập số liệu vào một biến trung gian, sau đó mới gán cho thành phần cấu trúc. Cách làm như sau:</ul> 


```c int x;
scanf("%d",&x);
nguoi_b.ngay_vao_co_quan.nam = x;
``` 


- Chú ý 3.2 Để tránh dài dòng khi làm việc với các thành phần cấu trúc ta có thẻ dùng lệnh #define. Ví dụ câu lệnh scanf trong chú ý trên có thể viết theo cách sau:
</ul>

```c #define p nguoi_b.ngay_vao_co_quan
...
scanf("%d", &p.nam);
```

###2.4 Thành phần kiểu FIELD (Nhóm BIT)

- Các thành phần nguyên (unsigned hoặc signed) với miền giá trị nhỏ (như tuổi biến thiên từ 1 đến 100) có thể khai báo kiểu nhóm bit theo mẫu sau:</li>


```c struct date
{
	int a:8;
	int b:6;
	int c:8;
	int d:2;
} x;
```


- Khi đó sizeof(struct date) = 3 (3 byte). Khi dùng kiểu field cần lưu ý các điểm sau:</ul>

	Kiểu của field phải là int (unsigned haowjc signed).
        Dộ dài của mỗi field không quá 16 bit.
        Khi muốn bỏ qua một số bit thì ta bỏ trống tên trường.

- Ví dụ Khi viết:<ul>


```c int:8;
int:x;
``` 

- Tức là bỏ qua 8 bit thấp, x chiếm 8 bit cao của một word.</li>

        Không cho phép lấy địa chỉ thành phần kiểu field.
        Không thể xây dựng các mảng kiểu field.
        Không thể trả về từ hàm bằng một thành phần kiểu field.

- Chẳng hạn không cho phép viết:</ul>

        return x.d;

mà phải dùng thủ thật sau:
        int t = x.d;
        return t;

- Ứng dụng của nhóm bit: Nhóm bit thường được ứng dụng để:</ul>

        Tiết kiệm bộ nhớ.
        Dùng trong union để lấy ra các bit của một từ.

- Ví dụ:</ul>


```c union{
struct{
unsigned a1;
unsigned a2;
} s;
struct{
unsigned n1:1;
unsigned:15;
unsigned n2:1;
unsigned:7;
unsigned n3:8;
} f;
} u;
```


- Khi đó:</li>

        u.f.n1 là bit 0 ủa u.s.a1;
        u.f.n2 là bit 0 của u.s.a2;
        u.f.n3 là byte cao của u.s.a2;


###2.5 Mảng cấu trúc:


- Khi sử dụng một kiểu giá trị (kiểu int chẳng hạn) ta có thể khai báo các biến và các mảng kiểu int. Ví dụ khai báo:</ul>


	int a,b,c[10]; 

cho ta hai biến nguyên a, b và mảng nguyên c.

- Hoàn toàn tương tự như vậy: Có thể sử dụng một kiểu cấu trúc đã mô tả để khai báo các cấu trúc và các mảng cấu trúc.</li>


- Ví dụ 5.1 : Giả sử kiểu cấu trúc nhan_cong đã định nghĩa trong 2.2, khi đó khai báo</li>


    `struct nha_cong nguoi_a, nguoi_b, to_1[10], to_2[20];`

- Sẽ cho:</ul>

        Hai biến mảng cấu trúc nguoi_a và nguoi_b;
        Hai mảng cấu trúc to_1 và to_2;

- Mảng to_1 có 10 phần tử và mảng to_2 có 20 phần tử. Mỗi phần tử của chúng là một cấu trúc kiểu nhan_cong.</ul>


- Ví dụ 5.2 : Đoạn chương trình sau sẽ tính tổng lương của 10 nguoi ở to_1.</ul>


```c double s=0;
for (i=0; i<10;++i)
	s+= to_1[i].bac_luong;
```

- Ghi chú: Không cho phép sử dụng phép toán lấy địa chỉ đối với các thành phần của mảng cấu trúc. Chảng hạn không cho phép viết:</ul>

	&to_1[i].bac_luong (nếu kiểu của bac_luong là nguyen thì được);

###2.6 Khởi đầu cho một cấu trúc

- Có thể khởi đầu cho cấu trúc ngoài, cấu trúc tĩnh, mảng cấu trúc ngoài và mảng cấu trúc tĩnh bằng cách viết vào sau khai báo của chúng một danh sách các giá trị cho các thành phần.</ul>


- Ví dụ 6.1 Đoạn chương trình</ul>


```c struct date{
	int day; int month;
	int year;
	int yearday;
	char *month_name;
};

struct date dd = {4,7,1990,120,"December"};
```


- Xác định một cấu trúc (theo kiểu date) có tên là dd và khởi đầu cho các thành phần cảu nó. Như vậy: Nội dụng của dd.day là 4, của dd.month là 7, của dd.year là 1990, của dd.yearday là 120 và của dd.month_name là "December"</li>

    Chú ý nếu month_name được khai báo kiểu ký tự như:
    char moth_name[20]; thì các khởi đầu trên vẫn đúng.
    Ví dụ 6.2 Đoạn chương trình

```c struct month
{
	int number;
	char* name;
} year[12] = {
		{1,"january"},
		{2,"february"},
		...
		{12,"december"}
};
```

- Xác định và khởi đầu một mảng cấu trúc có tên là year bao gồm 12 phần tử. Vì mỗi phần tử của mảng lại là một cấu trúc (kiểu month) nên để khởi đầu cho mảng year, một cách hợp lý hơn cả là sử dụng 12 bộ khởi đầu cho 12 cấu trúc tương ứng.</ul>


- Chẳng hạn: {1,"january"} là bộ khởi đầu cho phần tử thứ nhất của mảng year.Cũng như đối với các mảng khác, khi khởi đầu một mảng cấu trúc ngoài (hoặc tĩnh) ta không cần chỉ ra kích cỡ của nó. Lúc đó kích cỡ của các mảng được khởi đầu sẽ được xác định một cách chính xác (khi dịch chương trình) thông qua số các bộ khởi đầu. Như vậy, đoạn chương trình trong ví dụ 6.2 có thể viết một cách khác như sau:</ul>


```c struct month
{
	int number;
	char* name;
} year[] = {
		{1,"january"},
		{2,"febuary"},
		...
		{12,"december"}
	};
```

Để xác định số phần tử của year ta có thể dùng toán tử sizeof theo cách sau:

	int n = sizeof(year)/sizeof(struct month);

- Nhận xét cuối cùng ở mục này là: Những gì đã nói về việc khởi đầu một mảng thông thường vẫn còn đúng đối với mảng cấu trúc, đó là:<ul>


<li>Chỉ cho phép khởi đầu các cấu trúc và mảng cấu trúc ngoài (tĩnh). Chúng sẽ nhận giá trị 0 nếu không được khởi đầu.</li>

<li>Nếu kích thước của mảng cấu trúc cần khởi đầu đã được khai báo là n thì số bộ khởi đầu (m) cần không vượt quá n. Mỗi bộ khởi đầu cho giá trị của một phần tử mảng cấu trúc. Khi m < n thì chỉ có m phần tử đầu của mảng được khởi đầu, (n - m) phần tử còn lại nhận giá trị 0.</li>

<li>Vởiệc khi đầu được thực hiện một lần khi dịch chương trình:</li></ul>



- Ví dụ khi dịch đoạn chương trình</li>


```c struct
	{
		float a;
		int b;
		char* c;
	}
d[10] = {
			{7.1,5,"alpha"},
			{-10.6,8,"beta"}	
		};

```

- Chỉ hai phần tử đầu mảng cấu trúc d được khởi đầu. Trong ví dụ này n = 10 và m = 2;</ul>


###2.7 Phép gán cấu trúc:

* Có thể thục hiện phép gán trên ác biến và phần tử mảng cấu trúc cùng kiểu như sau:</ul>

	Gán hai biết (cấu trúc) cho nhau.
	Gán biến cho phần tử mảng (cấu trúc).
	Gán phần tử mảng cho biến.
	Gán hai phần tử mảng cho nhau.

* Mỗi phép gán nói trên tương đương với một dãy phép gán các thành phần tương ứng.


* Đoạn chương trình sau minh hoạ cách dùng phép gán cấu trúc để sắp xếp n thí sinh theo thứ tự giảm của tổng diểm. 


```c struct thi_sinh
{
	char ht[25]; /*họ tên*/
	float td; /*tổng điểm*/
} tg, ts[1000];
int i, j, n;
for (i = 1; i <= n - 1; ++i)
for (j = i + 1; j <= n; ++j)
	if (ts[i].td < ts[j].td)
	{
		tg = ts[i];
		ts[i] = ts[j];
		ts[j] = tg;
	}
```


* Truy xuất đơn giản 

Biến cấu trúc: `<biến cấu trúc >.<biến thành phần>;`

biến con trỏ: `<biến con trỏ>a<biến thành phần>;`


* Truy xuất phức tạp 

Sử dụng đối với các cấu trúc lồng nhau:

* Cú pháp :

 `<biến cấu trúc>.<biến cấu trúc>.<biến thành phần>;`

Hoặc

 `<biến cấu trúc >...<biến cấu trúc>.<biến thành phần>;`

b. enum

* Enum là từ khá dùng để khai báo một kiểu liệt kê (Enumeration). Kiểu liệt kê là một tập hợp các hằng số do người dùng tự định nghĩa. Nói cách khác là một kiểu dữ liệu đặc biệt được dùng để định nghĩa một mối quan hệ thứ tự cho một tập hơp hữu hãn các tên  

<l>Đặc điểm của enum:
</li>

<li>Là một kiểu dẽ liệu tham trị </li>

<li>Enum không được phép kế thừa</li>

<li> Khai báo và sử dụng:
</li>
<li>Cú pháp: `enum<tên enum>{danh sách các biểu tượng hằng}`</li>


<a name="danhsachlienket"></a>


### 4. Danh sách liên kết

#### 4.1 Danh sách liên kết đơn

* Khác với stack, danh sách liên kết đơn cuxgn là một kiểu danh sách tuyến tính gồm các phần tử vào lần lượt theo thứ tự tuy nhiên nó khác stack với queue ở chỗ là nó được cấp phát trong bộ nhớ vở các phần tử rời rạc nhau, không nằm kề nhau tuy nhiên giữa các phần tử trước thì có một liên kết đến phần tử sau nó.

#### 4.2 Danh sách liên kết kép 

* Về cơ bản nó giống với danh sách liên kết đơn  chỉ khác là chỗ ở mỗi nút nó có thêm con trỏ prev để trỏ tới phần tử trước nó trong danh sách liên kết kép thay vif chỉ có mỗi next đối với danh sách liên kết đơn.

<a name="sudungcapphattinhdong"></a>

### 5 Sử dụng cấp phát tĩnh và động 
* Bộ nhớ cấp phát tĩnh là bộ nhớ được HĐH cấp phát cho tiến trình ngay khi khởi tạo nó. Kích thước cố định và biết trước.

