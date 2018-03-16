## Tìm hiểu về markdown  
> Tham khảo: 
    http://bit.ly/2cxplkv
    http://bit.ly/2cxrr2B
>
> Người thực hiện: Xu Xu
>
> Cập nhật lần cuối: **26/02/2018**
>

### Mục lục
[1. Markdown](#timhieu)

[2. Các cú pháp thường gặp](#cuphap)

-	[2.1 Thẻ tiêu đề](#the)
-	[2.2 Chèn link, chèn ảnh](#chen)
-	[2.3 Ký tự in đậm, in nghiêng]
-	[2.4 Trích dẫn, bo chữ]
-	[2.5 Gạch đầu dòng]
-	[2.6 Tạo bảng]	
-	[2.7 Liên kết với tài khoản github bằng SSH]
[3. Cài đặt các công cụ hỗ trợ markdown](#congcuhotro)

[4. Các công cụ hỗ trợ editor]

<a name="markdownlagi"></a>

### 1. Markdown

Markdown là ngôn ngữ được tạo ra vào nawm2004 bởi John Gruber với sự đóng góp đáng kể từ Aaron Swariz, với mục đích cho phép người viết sử dụng, dễ viết các định dạng căn bản dễ đọc và tùy chọn chuyển  nó thành các mã XHTML hợp lệ (hoặc HTML).


<a name="caccuphapthuonggap"></a>

### 2. Các cú pháp thường gặp

#### 2.1 Thẻ tiêu đề


Markdown sử dụng kí tự # để bắt đầu cho các thẻ tiêu đề, có thể dùng từ 1 đến 6 kí tự # liên tiếp. Mức độ tiêu đề giảm dần từ một đến 6 tùy theo mục đích và ý thích.

Ex: `#1 Tiêu đề c 1`
    
#Tiêu đề 1

    `##1.1 Tiêu đề cấp 2`

#### 2.2 Chèn link, chèn ảnh 

Để chèn link hyperlink bạn chỉ cần paste luôn link đó vào file.md
Hoặc có thể sử dụng cú pháp sau để rút ngắn đường link:

[Github](https://github.com)

Để chèn ảnh hãy sử dụng cú pháp sau:

<img src="https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=2ahUKEwj88uHRwMPZAhWBMZQKHb__BogQjRx6BAgAEAY&url=https%3A%2F%2Fnews.zing.vn%2Fcach-de-chup-anh-dep-bang-smartphone-post803090.html&psig=AOvVaw3lM7N3SQXKj6T9k1Xpg7PK&ust=1519731898404064">

#### 2.3 Kí tự in đậm in nghiêng

Để in nghiêng một đoạn text bạn chỉ cần làm như sau:

*Xu xinh xắn*

#### 2.4 Trích dẫn, bo chữ

Bo một đoạn text bạn chỉ cần sử dụng

`ahihi`

Để làm nổi bật một đoạn hay file cấu hình chỉ cần sử dụng

```sh
auto eth0
iface eth0 inet static
ipaddress 10.10.10.10
netmask 255.255.255.0
gateway 10.10.10.1
dns-nameservers 8.8.8.8
```
#### 2.5 Gạch đầu dòng

Để gạch đầu dòng:

```- Gạch đầu dòng thứ nhất
   </ul>
   <li>Thụt với đầu dòng 1```


#### 2.6 Tạo bảng

Sử dụng cấu trúc sau để tạo bảng

| Cột 1 Hàng 1 | Cột 2 | Cột 3 | Cột 4|
|------------|-------|-------|------|
| Hàng 2 | 2 x 1 | 2 x 2 | 2 x 3 | 2 x 4 |


- Mẹo
  <ul>
  <li>Sử dụng trang http://markdownlivepreview.com/ paste vào đó đoạn markdown bạn viết và xem trước để chỉnh sửa cho phù hợp.</li>

  <li>Bạn cũng có thể sử dụng những đoạn markdown của người khác đã viết trước để tham khảo.</li>
  </ul> 
 
OK!

### 3. Cài đặt các công cụ hỗ trợ
 Sublime Text 3

Đầu tiên truy cập trang chủ để download
	`https://www.sublimetext.com/3`
Lựa chọn phiên bản để tải về

<img src=https://imgur.com/a/MWgsa>

Chạy file setup lên, màn hình welcome xuất hiện nhấn next 

<img src=https://imgur.com/a/3zZ1l>

Tùy chỉnh thư mục muốn cài đặt, nhấn next 

<img src=https://imgur.com/a/bDwgE>

Tiêp tục nhấn next 

<img src=https://imgur.com/a/7rjqc>

Nhấn install để cài đặt.

<img src=https://imgur.com/a/7V2sF>

Tương tự!

### 4 Các công cụ editor 


    https://stackedit.io/editor

    http://jbt.github.io/markdown-editor/

    http://www.tablesgenerator.com/markdown_tables






