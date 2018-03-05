# RE_basic
## Nhập môn C( tiếp theo)

> Tài liệu tham khảo: 
- http://bit.ly/2dwYc2u 
- http://bit.ly/1DPNtpD
- http://bit.ly/1FkfILU
> 
> Người thực hiện: Xu Xu
>
> Cập nhật lần cuối: **28/02/2018**
>

### Mục lục

[1. Tổng quan về quá trình cấp phát và giải phóng bộ nhớ](#Tongquan)

-	[1.1 Dẫn nhập](#dannhap)

-	[1.2 Cấp phát bộ nhớ](#capphat)

-	[1.3 Giải phóng bộ nhớ](#giaiphong)

-	[1.4 Memory leak](#leak)

- 	[1.5 Cấp phát bộ nhớ cho con trỏ](#tt)

-		[1.5.1 Tổ chức bộ nhớ trong máy tính](#tochuc)

-		[1.5.2 Tại sao cần phải cấp phát bộ nhớ cho con trỏ?](#Capphatbonhochocontro)

-		[1.5.3 Trong C có mấy cơ chế cấp phát bộ nhớ?](#coche)

-		[1.5.4 Tại sao cần phải giải phóng bộ nhớ?](#why)
[2. Tìm hiểu bản chất con trỏ từ cơ bản tới nâng cao](#contro)

-	[2.1 Bộ nhớ](#memory)

-	[2.2 Tổng quan](#tongquan)

-	[2.3 Khai báo](#khaibao)

-	[2.4 Khởi tạo](#khoitao)

-	[2.5 Kiểu dữ liệu con trỏ và các phép toán trên con trỏ](#cacpheptoan)

-	[2.6 Con trỏ với mảng, xâu, cấp phát bộ nhớ động ](#capphatbonhodong) 

-	[2.7 Con trỏ với hàm, con trỏ hàm](#controham)

-	[2.8 Con trỏ đa cấp](#controdacap)


[3. Viết báo cáo chi tiết các phần tìm hiểu](#baocao)

[4. Bài tập](#baitap)



<a name="Capphatvagiaiphonggbonho"></a>

### 1. Tổng quan về quá trình cấp phát và giải phóng bộ nhớ


#### 1.1 Dẫn nhập 

- Bộ nhớ là một tài nguyên quan trọng trong hệ thóng, được phân phối, điều phối phức tạp.</ul>

#### 1.2 Cấp phát bộ nhớ 

- Bộ  nhớ quan trọng nên cần thận trọng khi sử dụng, rất nhiều tiến trình cần tới bộ nhớ.
</ul>

Cấp phát bộ nhớ bản chất là `Trao quyền sử dụng`

	Khi ta xin cấp phát xong thì vùng nhớ đó hoàn toàn có giá trị ngẫu nhiên

	Khi ta cấp phát đi cùng với ép buộc sẽ được vùng nhớ có giá trị như mong muốn

#### 1.3 Giải phóng bộ nhớ

- Giải bộ nhớ bản chất là trả `Trả lại quyền sử dụng`</ul> 

Trả  lại thì đương nhiên khổ chủ sẽ không được phép sử dụng hay can thiệp vào bộ nhớ. 

#### 1.4 Memory leak 

- Bộ nhớ bị rò rỉ khi người dùng không ` Trả lại quyền sử dụng ` Nhiều lần như thế, hệ thống sẽ không còn bộ nhớ để cấp phát.</ul>

#### 1.5 Cấp phát bộ nhớ cho con trỏ 

##### 1.5.1 Tổ chức bộ nhớ trong máy tính

Trước hết hãy tìm hiểu bộ nhớ trong máy tính được tổ chức thế nào. Dưới đây là hình ảnh minh họa cho thứ tự các phân vùng trên bộ nhớ ảo:

<img src="http://minhhn.com/wp-content/uploads/2017/07/To_Chuc_Bo_Nho_May_Tinh_minhhn.com_.png">

- COde Segment </ul>

Code segement (text segement): Là nơi lưu trữ mã máy dạng nhị phân. Có nghĩa là các chương trình mà chúng ta code là code trên ngôn  ngữ tự nhiên, nhưng khi ở phân vùng này nó sẽ ở dạng mã máy nhị phân. Code segement chỉ chịu sự chi phối của hệ điều hành, người lập trình không thể can thiệp trực tiếp đến phân vùng này.

- Data Segement </ul>

Data segement (intialized data segement): là nơi chứa các biến kiểu static, biến toàn cục (global variable)

- BSS Segement </ul>

BSS Segement (uninitialixed data segement) cũng được dùng để lưu trữ các kiểu biến static, biến toàn cục (global variable) nhưng chưa được khởi tạo giá trị cụ thể.

- Heap </ul>

Là vùng nhớ không do CPU quản lí, người lập trình phải tự quản lí vùng nhớ này. Nó được sử dụng khi thực hiện cấp phát bộ nhớ động dùng cho con trỏ.

- Stack

Call stack là vùng nhớ do CPU quản lí, người lập trình không thể can thiệp vào vùng nhớ này. Nếu cố tình can thiệp sẽ bị lỗi ( code bên dưới, bạn chạy thử xem nó hiện thông báo lỗi như thế nào).
Vùng nhớ Stack được dùng để cấp phát bộ nhớ cho tham số của các hàm (function parameters) và biến cục bộ (local variables).

<img src="http://minhhn.com/lap-trinh-c/cap-phat-va-giai-phong-bo-nho-trong-lap-trinh-c/">

##### 1.5.2 Tại sao cần cấp phát bộ nhớ cho con trỏ

- Vì nếu không cấp ph bộ nhớ cho con trỏ thì chúng ta *không thể nhập dữ liệu trực tiếp cho con trỏ  * </ul>

Có thể hiểu khi muốn chỉ cho con trỏ,không có bộ nhớ thì không có chỗ để nhập dữ liệu.

Trong trường hợp ta chỉ cho con trỏ, con trỏ đến ô nhớ của biến khác n không cần phải cấp phát bộ nhớ nữa. vì khi đó con trỏ đã có ô nhớ để nhập d liệu cho nó rồi.ên


##### 1.5.3 Trong C có mấy cơ chế cấp phát bộ nhớ

Trong C có 3 cơ chế cấp phát:

	malloc
	calloc
	realloc

*Lưu ý: Vì giá trị khởi tạo cho vùng nhớ sau khi cấp phát thành công của hai cơ chế malloc và calloc là khác nhau. Do đó, tùy vào mục tiêu sử dụng mà dùng cơ chế phù hợp. Nếu bạn không quan tâm đến giá mặc định của vùng nhớ được cấp thì dùng malloc còn nếu muốn tất cả giá trị của bộ ô nhớ sau khi được cấp là 0 thì dùng calloc.*

	Khai báo cấp hoạt động bằng cơ chế malloc
	int *a = ( int* )calloc(10, sizeof(int));
	Tương đương set giá trị mặc định cho toàn bộ o nhớ sau khi cấp phát bằng 0
	memset (a, 0, 10 * sizeof( int ));


#### 1.5.4 Tại sao cần giải phóng bộ nhớ?

- Vì bộ nhớ khi cấp phát cho con trỏ thuộc vùng nhớ HEAP (là vùng nhớ CPU không quản lý. người lập trình phải tự quản lí vùng nhớ này) nếu như chúng ta không giải phóng thì những ô nhớ đấy sẽ không bao giờ được giải phóng, do đó có thể đên một lúc nào đó sẽ xảy ra tình trạng tràn bộ nhớ, deeanx đến máy bị đứng bị treo máy. Maý tính bây giờ cấu hình mạnh nên ít gặp. Tuy nhiên bộ nhớ có hạng, hãy tiết kiệm vì chính bạn, sử dụng xong thì nên giải phóng. </ul>

- Vậy có nghĩa là khi giải phóng bộ nhớ thì giá trị của con trỏ đang có sẽ bị mất? Điều này không đúng. Nếu như ngay khi chúng ta khai báo giải phóng mà có một tiến trình khác chiếm hữu ô nhớ đó thì giá trị hiện tại trên ô nhớ đó sẽ không còn nữa, còn nếu như không có tiến trình thì giá trị vẫn còn. </ul>

	Bản chất giải phsng bộ nhớ là thông báo chương trình biết là vùng nhớ đã sử dụng xong rồi không còn dùng nữa, hệ điều hành có thể sử dụng nó cho một tiến trình khác. Còn việc giá trị của vùng nhớ sau khi được giải phóng còn hau không thì chúng ta không biết được.

### 2 Tìm hiểu bản chất của con trỏ từ cơ bản tới nâng cao

(#memory)

1. Bộ nhớ ảo là gì?

Virtual memory là một kĩ thuật cho phép một chương trình ứng dụng tưởng rằng mình đang có một bộ nhớ liên tục (Một không gian địa chỉ) trong khi bô nhớ này có thể bị phân mảnh trong bộ nhớ vật lí và thâm chí có thể lưu trữ cả trong đĩa cứng. SO với các hệ thống không dùng kĩ thuật bộ nhớ ảo. các hệ thống dùng kĩ thuật này cho phép các lập trình các ứng dung lớn được dễ dàng hơn và sử dụng bộ nhớ vật lí thực ( ví dụ RAM) hiệu quả hơn.

Lưu ý rằng khái niệm virtual memory khong chỉ có nghĩa sử dụng không gian để mở rộng kích thước bộ nhớ vật lý nghĩa là chỉ mở  rộng hệ thống bộ nhớ để bao gồm cả đĩa cứng. Viêc mở rộng bộ nhớ tới các ổ đĩa hỉ là một hệ quả thông thường của việc sử dụng các kĩ thuật của bộ nhớ ảo. Trong khi đó, việc mở rộng này có thể được thực hiện bằng các phwong pháp khác như kĩ thuật overlay hoặc chuyển toàn bộ các chương trình cùng dữ liệu của chúng ra khỏi bộ nhớ khi các chương trình này không ở trạng thái họat động. Định nghĩa của bộ nhớ ảo có nên tảng là không gian địa chỉ bằng một dải liên tục các địa chỉ bộ nhớ ảo để đánh lừa các chương trình là chúng đang dùng khối lớn các địa chỉ liên tục.

2. Địa chỉ ảo là gì? 

Trong vùng bộ nhớ ảo kia, để cho tiến trình dễ sử dụng hệ điều hành dễ hiểu, hai th này cùng nhau quy định rằng, chỉ nhỏ ra theo từng byte , và đánh số từ một đến hết.

	Mỗi tiến trình có một vùng nhớ ảo riêng
	Vùng nhớ ảo là một không gian địa chỉ ảo trải dài từ thấp đến cao (từ 0 x 0000 -> cao hơn)
	Ở trong win 32bit thì không gian địa chỉ ảo có địa chỉ từ 00000000h trải đến 7fffffffh
	Bạn cần hiểu nó là địa chỉ ảo, không phải vùng nào cũng có bộ nhớ vật lý thật đâu nhé.
	Khái niệm về bộ nhớ phân đoạn: segement offset bạn hãy bỏ qua đi nó quá cũ rồi.





#### 2.2 Tổng quan

1. Cái nhìn vấn đề 

Con trỏ chỉ là một biến nguyên bình thường, chưa cái mà được gọi là địa chỉ ảo. 

Trong win 32bit thì địa chỉ ảo có độ dài 32 bit, tương ứng với số haxa có 8 chữ số, nó chỉ có 32bit vì chừng đó là vừa đủ để chỉ trỏ hết vùng bộ nhớ ảo.

2. Con trỏ ... là gì? 

Với một đứa nhập môn như tôi thì khái niệm này khá gay go đấy. 

Cứ note một cái quan trọng, cực kì quan trọng (người ta nói): Con trỏ là một công cụ, là một kiểu dữ kiệu để ta cài đặt các giải thuật.


#### 2.3 Khai báo 

1. Cấu trúc khai báo

- Kiểu dữ liệu ở đây có thể là
<ul>
<li> Kiểu dữ liệu có sẵn (built-in data type): int, char, double, long, ....</li>
<li> Kiểu dữ liệu cấu trúc do người dùng định nghĩa (user-denied data type): struct, union</li>
<li> Kiểu dữ liệu dẫn xuất + kiểu con trỏ hàm (các chap adv nhé) </ul>

Kiểu dữ liệu của cái vùng nhớ mà nó trỏ đến

Khai báo biến con trỏ: Tùy thuộc kiểu dữ liệu ta có tương ứng một biến con trỏ kiểu đó.

Kiểu* Tên biến con trỏ;

`Quy đính vùng trỏ tới của con tr`

Ta dùng toán tử và đẻ lấy địa chỉ của một biến con trỏ và sau đó gán địa chỉ đó cho biến con trỏ.

	Tên con trỏ = &biến;

Ex: p=&a 

`Cách truy xuất`

Với con trỏ px bên trên ta có 2 phép truy xuất là:

	px: lấy địa chỉ mà nó lưu giữ (trỏ tới)
	*px: lấy giá trị trong vùng nhớ mà nó trỏ tới
Trong ví dụ lên ta có thể thấy sau phép gán px = &x thì ta biết:

	px sẽ tương đương với &x
	*px sẽ tương đương với x và ta có thể sử dụng *px trong các phép toán, biểu thức.

#### 2.4 Khởi tạo

1. Khởi tạo là gì?

khởi tạo hoàn toàn khác với khai báo, khi ta khai báo thì câu lệnh đầu tiên thiết lập giá trị cho biến đó thì đó là khởi tạo. 

2. Khởi tạo trong biến con trỏ
	Tên con trỏ= địa chỉ;

Trong đó tên con trỏ là tên của biến con trỏ
Địa chỉ là vùng địa chỉ mà ta muốn trỏ đến
 ` Bản thân p cũng là một biến nguyên, p cũng nằm trong bộ nhớ, cũng có địa chỉ riêng`
`Toán tử & ở đây chính xác phải gọi là unary operator &  toán tử & một ngôi, nó hoàn toàn khác với toán tử ^2 ngôi (bitwwise). Toán tử & ngôi hay dùng để lấy địa chỉ của một biến. Khi đông đến lú thuyết về con trỏ ta đã sử dụng toán tử này rồi đó: scanf("%d",&a)`

3. Có được gì sau khi khởi tạo như ví dụ trên

Khi giá trị nằm trong p là địa chỉ của a thì ta nói p trỏ vào a

Lúc này thì *p hoàn toàn tương đương với a, người ta coi *p là bí danh của a, thao tác với *p cũng như thao tác với a, thao tác với a cũng như thao tác với *p

`Lúc này lệnh scanf("%d", &a); có thể thay bằng scanf("%d",p);`


*Chú ý toán tử "*" * đây là toán tử một ngôi, tác dụng là truy xuất đến ô nhớ mà con trỏ đang trỏ đến
Để tránh những hiểu lầm không đáng có khi có sự đang nhập mà bạn không thể đoán được, hãy thêm cặp () (*p)++ 
a+(*p)*c // thêm vào cho nó sáng sủa code ra.


4. Một số trường hợp

- Hiểu lầm về cách p trỏ về a</ul>
- Cùng trỏ vào một biến </ul>
- Con trỏ đa cấp </ul>
- COn trỏ trỏ đến ô nhớ đã biết </ul>
- Con trỏ void </ul>

Con trỏ void là một con trỏ đặc biệt thích trỏ đi đâu thì trỏ 

#### 2.5 Kiểu dữ liệu con trỏ và các phép toán trên con trỏ

1. Kiểu dữ liệu con trỏ

Khi ta viết int *p, b; chúng ta luôn viết gán a, vì sao? Vì * này là của p, p là con trỏ b không phải là con trỏ
Kiểu dữ liệu của b là int
Kiểu dữ liệu của p là (int*)

- Nên code theo chuẩn mực của Microsoft <ul>

<li> Trong câu lệnh khai báo con trỏ viết * gắn tên con trỏ</li>
<li> Khi viết kiểu dữ liệu viết * đứng gần kiểu dữ liệu cơ bản: cụ thể trả về của hàm, ở tiêu đề và nguyên mẫu hàm </li>
<li> Ở câu lệnh ép kiểu thì manual theo bạn muốn, có thể viết ra cho thoáng code</li></ul>

2. Các phép toán trên con trỏ

a. Phép gán

- Phép gán đối với con trỏ thì tham khảo phấn khởi tạo nhưng có một vài yếu tố sau đây:
<ul>
<li> Tất cả các loại con trỏ đều có phép gán </li>
<li> Phép gán với con trỏ yêu cầu vế tráu là mộ con trỏ và vế phải là một địa chỉ </li>
<li> Phép gán yêu cầu sự tương xứng về kiểu dữ liệu, nếu không tương xứng chúng ta phải ép kiểu

Ví dụ: `p=(int*)8232`
	p có kiểu dữ liệu là int* còn 8232 là một hằng nguyên , nên phải ép kiểu về in rôi thực hiện phép gán.
<li> Phép gán với một con trỏ kiểu void không cần thiết phải tương xứng hoàn tòan về kiểu dữ liệu, void* có thể tương ứng với tất cả (ví dụ như ở chap trước), thậm chí là vượt cấp. </li> </ul>

b. Phép so sánh 

- Phép so sánh ngang bằng dùng để kiểm tra hai con trỏ vào cùng một vùng nhó hay không, hoặc kiểm tra con trỏ đang trỏ vào NILL hay không ( trong trường hợp cấp phát động, mở file, mở resource ...)</ul>

- Phép so sánh lớn hơn nhỏ hơn : >, <, <=, >= sử dụng để kiểm tra độ cao thấp giữa hai địa chỉ. Con trỏ nào nhỏ hơn thì trỏ vào địa chỉ thấp hơn.<ul>

<li> Được quyền so sánh mọi con trỏ với 0, vì 0 chính là NULL </li>

<li> Ngoài ra khi so sanh hai con trỏ hoặc con trỏ với một địa chỉ xác định ( số nguyên ) cần có sự tương xứng về kiểu dữ liệu </li>

<li> Con trỏ void có thể đem ra so sánh với các con trỏ khác </li></ul>

c. Phép cộng trừ và phép tăng giảm: + += - -= ++ --

Bản chất của việc tăng giảm con trỏ p di một đơn vị là cho p trỏ đến ô nhớ bên cạnh phía dưới/ trên.

- Chú ý:<ul>

<li> Khi tăng giảm con trỏ p đi một đơn vị không có nghĩa là trỏ sang byte bên cạnh </li>

<li> Việc tăng giảm con trỏ đi một đơn vị phụ thuộc vào kiểu dữ liệu và nó trỏ đến, quy tắc là p+1 >>> giá trị chưa trong p + sizeof ( kiểu dữ liệu của biến mà p trỏ đến)</li>

<li> Không có phép tăng giảm trên con trỏ void </li>

<li> Không có phép tăng giảm  trên con trỏ hàm </li>

<li> Không có phép cộng hai con trỏ với nhau </li>

<li> Phép trừ con trỏ trả về độ lệch giữa hai con trỏ <li></ul>

Vậy là ra có kết luận như sau : `kiểu dữ liệu trỏ đến có tác dụng các thực rõ ràng tất cả các phép toán trên con trỏ (bao gồm cả phép = * &`

3. Ứng dụng 

- Ứng dụng duyệt xâu </ul>

- Ứng dụng đổi số thực thành số nhị phân </ul>

- Ứng dụng tìm ( số float lớn hơn không) nhỏ nhất</ul>

####2.6 Con trỏ với mảng, xâu, cấp phát bộ nhớ động 

1. Hằng con trỏ - const poiner ? Con trỏ hằng, poiner to const?

a. Hằng là gì?

Ta đã biết hằng số (toán học ) là những đại lượng có giá trị không đổi, trong lập trình là những đại lượng có giá trị không đổi trong suốt chương trình.

Hằng trong c/ C++/ C++ox có định kiểu rõ ràng
Hằng trong C/ C++/ C++ox được định nghĩa bằng từ khóa const

Chú ý: Có một số người hiểu lầm rằng dùng từ khóa define định nghĩa hằng số, đây thật sự là một cách hiểu sai lầm hoàn toàn. Define định nghĩa trên macro và có rất nhiều sự khác nhau khi ta dùng define và const 

b. Hằng con trỏ?

- Hằng con trỏ có hai loại như sau: <ul>

<li> Những con trỏ mà chỉ trỏ vào cố định vào một vùng nhớ, những con trỏ này không có khả năng trỏ vào vùng nhớ khác, không thay đổi được</li>
<li> Những con trỏ mà trỏ vào một vùng nhớ cố định, con trỏ này chỉ có tác dụng trỏ đến chứ không cos khả năng thay đổi gía trị của vùng nhớ này, con trỏ này được ứng dụng gần như là tác dụng của phương thức hằng trong OOP </li></ul>

Để tiện phân biệt, mình gọi 1 là hằng con trỏ và hai là con trỏ hằng, và chúng ta có thể gộp cả hai kiểu này để thành một kiểu mới

`Ứng dụng lớn nhất của char const là chú ý khi khai báo và sử dụng các hàm trả về const`

2. Mảng liên quan gì đến con trỏ và cho bài viết này?

Khi ta khai báo mảng thì tương đương với xin cấp phát một vùng nhwos có kích thươc như bạn khai báo và khai báo ra 1 hằng con trỏ vào đầu vùng nhớ đó

int a[100];

<li> có thể coi a là một hằng con trỏ trỏ vào phần tử thứ 0 của mảng nhé, a mang đầy đủ tính chất của một hằng con trỏ nhưng có thêm một số khác biệt nhỏ ( ví dụ như khi dùng sizeof)</li>

<li> các phép toán nhằm làm a trỏ tới vùng khác (thay đổi giá trị của a) là không thể (++ -- =)</li>

<li> a tương đương với &a[0]</li>

<li> a + i tương đương với &a[i] </li>

<li> *a tương đương với a[0]</li>
 
<li> *(a+i tương đương với a[i])</li>

`Chú ý: trình biên dịch luôn hiểu a[i] là *(a+i)`

3. Con trỏ hằng là gì?

- Con trỏ hằng là một optional ability trong lập trình, tác dung của nó tựa như là ( gần như thôi. không thể bằng được) phương thức hằng trong C++;</ul>

- Ý nghĩa là một con trỏ, trỏ đến một ô nhớ. nhưng không được quyền thay đổi giá trị của ô nhớ đó!!! </ul>

4. Thế còn xâu kí tự?

<li>  Xâu kí tự là trường hợp đặc biệt của mảng 1 chiều khi mà các thành phần của mảng là một byte </li>

<li> Xâu kí tự kết thúc bằng NULL, NULL là một kí tự đặc biệt có mã là 0. Có ba cách để viết NULL trong C như sau: NULL, '/0', 0\</li>

a. Sai lầm thường gặp khi làm việc với xâu kí tự

- Đối với xâu kí tự thì các bạn phải nhớ các trường hợp sau:
<ul>
<li> Chưa có bộ nhớ đã sử dụng như đúng rồi </li>

<li> Thay đổi giá trị của một hằng </li>

Nguyên nhân sâu sa của vấn đề là: khi khai báo char*xau="Xuxinhxan" thì bản chất là:
	Trong vùng nhớ data của chương trình sẽ có một hằng chuỗi "Xuxinhxan "  là hằng chuỗi, đã là hằng thì không thể thay đổi.
	Con trỏ xâu trỏ đến đầu của vùng nhớ đó. 

<li> Cố tình thay đổi giá trị của một hằng </li> 

<li> Dùng phép toán so sánh để so sáng nội dung 2 xâu </li></ul>

b. Thêm một style duyệt xâu mới

5. Cấp phát động.

a. Bản chất của việc cấp phát động 
b. Cấp phát ddooojng như thế nào?

C: contro = (ép kiểu)malloc(...)

	Trong C chủ yếu sử dụng các hàm trong alloc.h

<li>malloc trả về một địa chỉ đến một vùng nhéo và coi vùng nhớ này là void*, nên trong câu lệnh luôn đi kèm với ép kiểu </li>
<li> Cấp phát luôn là đi kèm với giải phóng, ở đâu cũng thế.</li>

#### 2.7 Con trỏ với hàm, con trỏ hàm

1. Hàm cũng có địa chỉ

Khi chương trinhf chạy thì các hàm nằm bên chương trình đó được load lên không gian nhớ ảo, VA space, chúng nằm trong vùng nhớ cade.

2. Con trỏ hàm

Con trỏ hàm là một điều thú vị trong C/C++ bản chất là một con trỏ có định kiểu ta có thể sử dụng con trỏ hàm để gọi hàm khi đã biết địa chỉ của hàm. 

3. Hằng con trỏ hàm

Khái niệm này hơi giống với khái niệm hằng con trỏ với mảng một chiều. Khi khai báo hàm thì tên hàm chính là con trỏ hàm, con trỏ này trỏ cố định vào vùng nhớ của hàm.

4. Ứng dụng của con trỏ hàm

5. Con trỏ với hàm

CÓ nhiều người nghĩ rằng trong C ta có thể sẻ dụng con trỏ trong tham số của hàm như là một tham biến, qua hàm ta có thể thay đổi được giá trị của tham số. WTF?

- Nguyên nhân: <ul> 
<li> Hàm trong C không hề có tham biến, hàm trong C đều hoạt động theo nguyên tắc sau:
	Khi gọi hàm, một bản sao của tham số được tạo ra (cấp phát vùng nhớ mới, copy giá trị sang) và hàm sẽ làm biệc với bản sao này.</li>
<li> Vậy khi làm việc với con trỏ phải làm thế nào?
	Trước khi gọi hàm con trỏ trỏ vào đâu thì nó vẫn được trỏ vào đấy.</li>
<li> Vậy tại sao lại có sự thay đổi và tại sao lại sử dụng con trỏ trong con trỏ hàm? Con trỏ không thay đổi thì cái gì thay đổi được? ` Gái trị nằm trng vùng nhớ tor đến thay đổi` do biến của ta nằm trong vùng nhớ được trỏ đến nên nó được thay đổi. </li></ul>

- Sai lầm trong hanhf động. 

<ul>
<li>Sai lầm vì trong hàm chúng ta cấp phát bộ nhớ rồi cho bản sao đang là mvieej trỏ đến, ra khỏi hàm tồi thì x của ta vẫn chưa có trỏ vào bộ nhớ nào cả.</li></ul>

6. Vậy làm thế nào để mà thay đổi giá trị của một con trỏ qua hàm?

7. Nâng cao về con trỏ hàm, mảng con trỏ hàm và kĩ năng phân tích vấn đề

#### 2.8 Con trỏ đa cấp

1. Con trỏ đa cấp là gì?

Tạm hiểu nó là chũng con trỏ có dạng hai hoặc nhiều chiều

Phép toán trên con trỏ cấp n (n>1) và con trỏ cấp hai thuần túy như trong ví dụ vừa khai báo trên

2. Con trỏ đa cấp dùng để làm gì?

Con trỏ dda cấp thường được dùng trong các trường hợp cần thay đổi giá trị của một con trỏ cấp thấp hơn khi ra khỏi hàm.

Con trỏ đa cấp hai còn được dùng như là con trỏ trỏ tơi một con trỏ, có thẻ dùng để xử lí ma trận hai chiều.

Con trỏ cấp ba conf được dùng như là con trỏ tro tới một con trỏ mà con trỏ nàu đang trỏ tiếp tới một con trỏ khác có thể dùng như ma trận ba chiều
	


