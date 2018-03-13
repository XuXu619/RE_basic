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


<a name="giaithich"></a>

### 1. Kiểu cấu trúc struct, enum 

a. Định nghĩa và khai báo

 - Định nghĩa: Dữ liệu cấu trúc là một kiểu dữ liệu bao gồm nhiều thành phần có kiểu khác nhau, mỗi thành phân được gọi là một trường (field)</ul> 

Kiểu cấu trúc khác mảng ở chỗ: các phần tử của mảng có cùng kiểu, trong khi các phần tử của cấu trúc có nhiều kiểu khác nhau. Như thws, một cấu trúc đơn giản có thể chứa các phần tử nguyên, các phần tử chấm động và các phần tử kí tự. Con trỏ, mảng và những kiểu cấu trúc khác cũng có thể được bao gồm như là những phần tử bên trong một cấu trúc.

- Khai báo biến: Cú pháp `struct< tên cấu trúc >< biến1 >< biến 2 > ....;`</ul>

- Truy xuất các trường của cấu trúc<ul>

<li> Truy xuất đơn giản </li>

Biến cấu trúc: `<biến cấu trúc >.<biến thành phần>;`

biến con trỏ: `<biến con trỏ>a<biến thành phần>;`

<li> Truy xuất phức tạp </li>

Sử dụng đối với các cấu trúc lồng nhau:

Cú pháp : `<biến cấu trúc>.<biến cấu trúc>.<biến thành phần>;`

Hoặc `<biến cấu trúc >...<biến cấu trúc>.<biến thành phần>;`

b. enum

- Enum là từ khá dùng để khai báo một kiểu liệt kê (Enumeration). Kiểu liệt kê là một tập hợp các hằng số do người dùng tự định nghĩa. Nói cách khác là một kiểu dữ liệu đặc biệt được dùng để định nghĩa một mối quan hệ thứ tự cho một tập hơp hữu hãn các tên </ul>

- Đặc điểm của enum:<ul>

<li>Là một kiểu dẽ liệu tham trị </li>

<li>Enum không được phép kế thừa</li>
</ul> 
- Khai báo và sử dụng:
<ul>
<li>Cú pháp: `enum<tên enum>{danh sách các biểu tượng hằng}`


<a name="cautruccontro"></a>


### 2. Cấu trúc con trỏ 

Khai báo: `struct<tên cấu trúc>*<tên biến>`

Truy cập các phần tử cấu trúc: dùng kí hiệu ->

c. Định nghĩa kiểu mới bằng typedef

Cú pháp: `Typedef<kiểu đã có><tên kiểu mới>`

<a = name="hamtrencautruc"></a>

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

### 5 Sử dụng cấp phát tĩnh và động 
- Bộ nhớ cấp phát tĩnh là bộ nhớ được HĐH cấp phát cho tiến trình ngay khi khởi tạo nó. Kích thước cố định và biết trước.</ul> 
- Bộ nhớ cấp phát động thì được HĐH cấp phát cho tiến trình trong quá trình nó hoạt động, tùy theo nhu cầu của tiến trình, kích thước thay đổi và không biết trước.</ul>




