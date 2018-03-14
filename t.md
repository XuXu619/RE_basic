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

a. Định nghĩa và khai báo


 - Định nghĩa: Dữ liệu cấu trúc là một kiểu dữ liệu bao gồm nhiều thành phần có kiểu khác nhau, mỗi thành phân được gọi là một trường (field)</ul> 

Về mặt ngữ pháp điều này hoàn toàn giống như việc khai báo các biến và các mảng. Khi kgai báo một biến cần chỉ ra kiểu và tên của nó.

Kiểu cấu trúc khác mảng ở chỗ: các phần tử của mảng có cùng kiểu, trong khi các phần tử của cấu trúc có nhiều kiểu khác nhau. Như thws, một cấu trúc đơn giản có thể chứa các phần tử nguyên, các phần tử chấm động và các phần tử kí tự. Con trỏ, mảng và những kiểu cấu trúc khác cũng có thể được bao gồm như là những phần tử bên trong một cấu trúc.

<li>Khai báo biến: Cú pháp `struct< tên cấu trúc >< biến1 >< biến 2 > ....;`</li>
Ví dụ khai báo:
        float x, y;

Cho ta hai biến kiểu float với các tên là x và y. Ta cũng sẽ làm y hệt như vậy khi khai báo biến cấu trúc. Giả sử ta đã có ác kiểu cấu trúc ngay va nhan_cong như trong các ví dụ 1.1 và 1.2 khi đó ta có thể xét các ví dụ sau:

Ví dụ 2.1 : Khai báo
       `struct ngay ngay_di, ngay_den;`

Sẽ cho ta hai biến cấu trúc với tên là ngay_di và ngay_den. Cả hai đều được xây dựng theo kiểu ngay.

Ví dụ 2.2 : Khai báo
        `struct nhan_cong, nguoi_a, nguoi_b;` 

Sẽ cho ta hai cáu trúc với tên là nguoi_a và nguoi_b. Cả hai đều được xây dựng theo kieu nhan_cong

Một cách tổng quát, việc khai báo cấu trúc được thực hiện theo mẫu:

    `struct tên_kiểu_cấu_trúc danh_sách_tên_cấu_trúc;`

Sau đây là một vài điều cần lưu ý:
        Nhận xét 2.1: Các biến cấu trúc được khai báo theo mẫu trên sẽ được cấp phát bộ nhớ một cách đầy đủ cho tất cả các thành phàn của nó.
        Nhận xét 2.2: Việc khai báo có thể thực hiện đồng thời với việc dịnh nghĩa kiểu cấu trúc. Muốn vậy chỉ cần đặt danh sách tên biến cấu trúc cần khai báo vào sau } cuối cùng trong mẫu 1.1

Nói cách khác: Đề vừa thiết kế kiểu vừa khai báo các biến cấu trúc ta sử dụng mẫu sau:

Mẫu 2.2

 `struct ten_kiểu_cấu_trúc` 
{
	các thành phần cảu cấu trúc
} danh sách tên biến cấu trúc

Ví dụ 2.3: Các cấu trúc ngay_di và ngay_den trong ví dụ 2.1 có thể được xây dựng theo cách:

```c struct ngay
{
	int ngay_thu;
	char ten_thang[10];
	int nam;
} ngay_di, ngay_den;
``` 

    Ví dụ 2.4: Các cấu trúc nguoi_a, nguoi_b trong ví dụ 2.2 có thể xây dựng theo mẫu sau (giải sử kiểu ngay đẫ được mô tả như ở ví dụ 1.1)

``` C++ struct nhan_cong
{
	char ten[15];
	char dia_chi[20];
	double bac_luong;
	struct ngay ngay_sinhl
	struct ngay ngay_vao_co_quan;
} nguoi_a, nguoi_b;
```

<li>Nhận xét 2.3 : Khi vừa định nghĩa kiểu (cấu trúc) vừa khai báo cấu trúc như trong ví dụ 2.3 và 2.4 ta có thể không cần đến tên kiểu cấu trúc. Nói cách khác các cấu trúc có thể được khai báo theo mẫu sau.</li> 

Mẫu 2.3 :

```c struct
{
	các thành phần cảu cấu trúc
} danh sách tên cấu trúc;```


Ví dụ 2.5: Các cấu trúc ngay_di và ngay_den trong ví dụ 2.3 được khai báo theo cách:

```c struct
{
	int ngay_thu;
	char ten_thang[10];
	int nam;
} ngay_di, ngay_den;``` 



- Cũng cần nói thêm sự khác nhau giữa mẫu 2.2 và mẫu 2.3. Điều ngày sẽ trở nên hoàn toàn rõ ràng khi so sánh ví dụ 2.3 và ví dụ 2.5 ở ví dụ 2.3 ngoài việc xây dựng được cấcc cấu trúc ngay_di, ngay_den ta còn cho ra đời được kiểu cấu trúc ngay. Kieẻu ngay có thể sử dụng để khai báo ở các cấu trúc khác. Ỏ ví dụ 2.4 ta chỉ đặt được mục đích đầu của ví dụ 2.3.</ul> 

Chú ý: Nếu dùng typedef để định nghĩa kiểu cấu trúc, thì khi khai báo ta chỉ cần dùng tên kiểu (bỏ từ khoá struct). Ví dụ như kiểu cấu trúc ngay dược định như trong chú ý 1.1 của 2.1 thì các cấu trúc ngay_di và ngay_den trong ví dụ 2.1 có thể khai báo như sau:

`ngay ngay_di, ngay_den;`


<li>Truy xuất các trường của cấu trúc
</li>

<li> Truy xuất đơn giản </li>

Biến cấu trúc: `<biến cấu trúc >.<biến thành phần>;`

biến con trỏ: `<biến con trỏ>a<biến thành phần>;`

<li> Truy xuất phức tạp </li>

Sử dụng đối với các cấu trúc lồng nhau:

Cú pháp : `<biến cấu trúc>.<biến cấu trúc>.<biến thành phần>;`

Hoặc `<biến cấu trúc >...<biến cấu trúc>.<biến thành phần>;`

b. enum

- Enum là từ khá dùng để khai báo một kiểu liệt kê (Enumeration). Kiểu liệt kê là một tập hợp các hằng số do người dùng tự định nghĩa. Nói cách khác là một kiểu dữ liệu đặc biệt được dùng để định nghĩa một mối quan hệ thứ tự cho một tập hơp hữu hãn các tên </ul>

<l>Đặc điểm của enum:
</li>

<li>Là một kiểu dẽ liệu tham trị </li>

<li>Enum không được phép kế thừa</li>

<li> Khai báo và sử dụng:
</li>
<li>Cú pháp: `enum<tên enum>{danh sách các biểu tượng hằng}`</li>


<a name="cautruccontro"></a>


### 2. Cấu trúc con trỏ 

Khai báo: `struct<tên cấu trúc>*<tên biến>`

Truy cập các phần tử cấu trúc: dùng kí hiệu ->

c. Định nghĩa kiểu mới bằng typedef

Cú pháp: `Typedef<kiểu đã có><tên kiểu mới>`

<a name="hamtrencautruc"></a>

### 3. Hàm trên cấu trúc

#### 3.1 Đối của hàm có thể là

<li> Biến cấu trúc khi đó tham số thực tương ứng là một giá trị cấu trúc.</li>
<li> COn trỏ cấu trúc, khhi đó tham số thực tuogw ứng là địa chỉ của biến cấu trúc. </li>
<li> Mảng cấu trúc hình thức hoặc con trỏ cấu trúc. Khi đó tham số thực tương ứng là tên mảng cấu trúc</li>

#### 3.2 Hàm có thể trả về các giá trị 

<li> Giá trị cấu trúc </li>
<li> Con trỏ cấu trúc </li>

<a name="danhsachlienket">

### 4. Danh sách liên kết

#### 4.1 Danh sách liên kết đơn

Khác với stack, danh sách liên kết đơn cuxgn là một kiểu danh sách tuyến tính gồm các phần tử vào lần lượt theo thứ tự tuy nhiên nó khác stack với queue ở chỗ là nó được cấp phát trong bộ nhớ vở các phần tử rời rạc nhau, không nằm kề nhau tuy nhiên giữa các phần tử trước thì có một liên kết đến phần tử sau nó.

#### 4.2 Danh sách liên kết kép 

Về cơ bản nó giống với danh sách liên kết đơn  chỉ khác là chỗ ở mỗi nút nó có thêm con trỏ prev để trỏ tới phần tử trước nó trong danh sách liên kết kép thay vif chỉ có mỗi next đối với danh sách liên kết đơn.

<a name="sudungcapphattinhdong"></a>

### 5 Sử dụng cấp phát tĩnh và động 
- Bộ nhớ cấp phát tĩnh là bộ nhớ được HĐH cấp phát cho tiến trình ngay khi khởi tạo nó. Kích thước cố định và biết trước.</ul> 
- Bộ nhớ cấp phát động thì được HĐH cấp phát cho tiến trình trong quá trình nó hoạt động, tùy theo nhu cầu của tiến trình, kích thước thay đổi và không biết trước.</ul>




