---
layout: single
title: "[Linux] CentOS 커널 교체하기" 
categories: Linux
sidebar:
    nav: "counts"

---

<style>
  body {
    font-size: 15px; /* 폰트 사이즈 조절 */
  }
</style>




<br>

<br>

# 커널 소스 다운받기

https://www.kernel.org/ 에 접속하면 HTTP 링크가 있다.

-  만약 인터넷이 되는 상황이라면 해당 링크를 통해 리눅스 터미널에서 직접 다운로드 받을 수 있다.
-  해당 링크에서 직접 다운받아서 cd/usr/src에 옮기는 방식도 가능하다.

<br>

| [HTTP] | https://www.kernel.org/pub/ |
| ------ | --------------------------- |
|        |                             |

<img src="{{site.url}}/images/2024-07-04-KernelUpdate/1.png" style="zoom:40%;" />

<br>

<br>

# 1. 커널 버전 확인

-  먼저 내가 사용중인 커널의 버전을 확인한다.

```bash
uname -r #사용 중인 커널 버전 확인
```

<br>

<img src="{{site.url}}/images/2024-07-04-KernelUpdate/2.png" style="zoom:40%;" />



<br>

<br>

# 2. 커널 소스 다운로드

-  미러 사이트에서 원하는 커널의 버전을 다운받는다.
   -  네트워크가 가능한 환경에서 터미널에서 wget 명령어를 통해 다운 받는다.
-  [`linux-3.17.4.tar.xz](<https://mirrors.edge.kernel.org/pub/linux/kernel/v3.x/linux-3.17.4.tar.xz>)`





https://mirrors.edge.kernel.org/pub/linux/kernel/v3.x/[linux-3.17.4.tar.xz](https://mirrors.edge.kernel.org/pub/linux/kernel/v3.x/linux-3.1.7.tar.xz)



```bash
cd /usr/src

wget "<https://mirrors.edge.kernel.org/pub/linux/kernel/v3.x/[linux-3.17.4.tar.xz](https://mirrors.edge.kernel.org/pub/linux/kernel/v3.x/linux-3.1.7.tar.xz)>"
```





<img src="{{site.url}}/images/2024-07-04-KernelUpdate/3.png" style="zoom:40%;" />

<br>

<br>

# 3. tar 압축 풀기

-  이제 해당 tar 파일의 압축을 풀어준다.

```bash
tar -xvf linux-3.17.4.tar.xz
```



<br>

<br>

# 4. 작업 폴더 이동하기

```bash
cd linux-3.17.4/
```



<br>

<br>

# 5-1. 컴파일 작업 준비하기(CLI)

-  커널 컴파일(빌드) 는 크게 2가지 방법이 존재한다. CLI를 이용하여 하는 방법과 GUI로 하는 방법이 있다.
   -  두 방법 모두 별도의 라이브러리 설치가 필요하다.
   -  5-1, 5-2 중 하나의 방법으로 컴파일 하면 된다.



<br>



### Red Hat 기반 배포판 

```bash
sudo yum install ncurses-devel
```



<img src="{{site.url}}/images/2024-07-04-KernelUpdate/4.png" style="zoom:40%;" />

make menuconfig 명령어를 입력하면 (ncurses-devel) 라이브러리 설치가 필요하다고 나온다.

OS마다 라이브러리의 이름이 조금씩 다르기 때문에 정확한 라이브러리 명을 확인한 후 설치 해야 한다.

<br>



```bash
cd /usr/src/linux-3.17.4
make menuconfig #ncurses 라이브러리가 필요
```

<img src="{{site.url}}/images/2024-07-04-KernelUpdate/5.png" style="zoom:40%;" />

<br>

<br>



## 5-2. 컴파일 작업 준비하기(GUI)

```bash
yum -y install gcc gcc-c++ qt qt-devel
```

`gcc` : GNU Compiler Collection의 C 컴파일러

`gcc-c++` : GNU Compiler Collection의 C++ 컴파일러

`qt`: Qt 라이브러리, C++로 작성된 오픈 소스 GUI 애플리케이션 프레임워크

`qt-devel` : Qt 라이브러리의 개발 패키지, 이 패키지에는 Qt 애플리케이션을 개발하는 데 필요한 라이브러리





<br>

<br>



## 6. 컴파일

make clean 명령으로 기존 커널 정보를 초기화 한 다음 커널 빌드(컴파일)하기.

```bash
make clean;
make; 
make_modules_install; 
make install;
```

-  `make clean`:
   -  이전 빌드에서 생성된 모든 객체 파일과 중간 파일을 삭제하여 디렉토리를 정리
-  `make`:
   -  Makefile에 정의된 지침에 따라 소스 코드를 컴파일하여 실행 파일 또는 라이브러리를 생성.
   -  Makefile은 소스 파일과 빌드 규칙을 정의
-  `make modules_install`:
   -  커널 모듈을 시스템에 설치, 커널 모듈을 컴파일
   -  시스템의 적절한 위치(보통 `/lib/modules/$(uname -r)/` 디렉토리)에 복사
   -  커널 모듈은 커널 기능을 확장하는데 사용
-  `make install`:
   -  Makefile에 정의된 설치 지침에 따라 빌드된 소프트웨어를 시스템에 설치합니다.
   -  설치 위치는 보통 `/usr/local/bin` 또는 `/usr/bin`과 같은 표준 디렉토리







시간이 굉장히 오래 걸린다…

<br>

<br>

# appendix

<br>



## GRUB 설정 업데이트

-  대부분의 경우, `make install` 명령어는 GRUB 설정 파일을 자동으로 업데이트한다. 하지만 이를 수동으로 확인하고 업데이트하는 것이 좋다.

```bash
sudo grub2-mkconfig -o /boot/grub2/grub.cfg  # RHEL/CentOS 7 이상
```



설치된 커널 목록 출력하는 방법

```bash
sudo grep -i 'menuentry ' /boot/grub2/grub.cfg
```



<br>

<br>



## 새 커널을 부팅 로더에 추가

/etc/default/grub

```bash
cat /etc/default/grub

vi /etc/default/grub

GRUB_DEFAULT=0
```

<br>

<br>



## 변경사항 저장

```bash
sudo grub2-mkconfig -o /boot/grub2/grub.cfg  # RHEL/CentOS 7 이상
```

------

<img src="{{site.url}}/images/2024-07-04-KernelUpdate/6.png" style="zoom:40%;" />

부팅 시 새로운 커널이 선택되는 것을 알수있다.



<br>

<br>



The CPU has been disabled by the guest operating system. Power off or reset the virtual machine.

**(게스트 운영 체제에서 CPU를 비활성화했습니다. 가상 머신의 전원을 끄거나 재설정합니다.)**

VMWARE가 튕김. 작동하지 않는다.

<br>

<br>

<br>

<br>

