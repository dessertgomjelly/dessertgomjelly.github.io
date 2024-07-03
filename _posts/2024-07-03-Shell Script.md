---
layout: single
title: "[Linux] Shell Script" 
categories: Linux
use_math: true #수학 공식 가능하게
sidebar:
    nav: "counts"
---

<style>
  body {
    font-size: 15px; /* 폰트 사이즈 조절 */
  }
</style>




**[LINUX STUDY]** [kkk1m](https://github.com/kkk1m) & [dessertgomjelly](https://github.com/dessertgomjelly) {: .notice--danger}



<br>

<br>

# 쉘 스크립트 란?

-  Shell Script는 유닉스 또는 리눅스 시스템에서 명령어를 자동화하는 데 사용 되는 텍스트 파일이다.
-  여러 개의 쉘 명령어와 스크립트 언어로 작성된 명령어들이 순차적으로 실행되도록 작성된 스크립트이다.

```
 터미널에 입력했던 여러 명령어들을 하나의 스크립트 파일에 나열하여, 스크립트 파일이 자동으로 실행 함으로 효율적이면서 간편하게 작업 처리를 할 수 있는 것이다.
```

<br>

<br>





# 주요 개념

-  **쉘(Shell)**

   -  사용자가 운영 체제와 상호 작용하는 인터페이스이다. 다양한 종류의 쉘이 있지만, 가장 많이 사용되는 것은 Bash(Bourne Again SHell)이다.

-  **스크립트 파일**

   -  쉘 스크립트는 일반적으로 

      ```
      .sh
      ```

       확장자를 가지며, 텍스트 편집기를 사용하여 작성된다.

      -  ex) vim [test.sh](http://test.sh)
      -  ex) nano [test.sh](http://test.sh)

<br>

<br>

# Shebang(`#!`)

-  Shebang은 `#`와 `!` 두 문자로 시작하기 때문에 붙여진 이름이다. 운영 체제에 스크립트를 실행할 때 사용할 인터프리터의 경로를 지정한다.
-  `/bin/bash`는 Bash Shell의 절대 경로이다. Bash Shell이 설치된 위치이자 유닉스 표준 경로이다.

```bash
#!/bin/bash
```

-  일반적으로 #는 주석이지만 #!와 같이 느낌표와 함께 쓰이면 이것은 느낌표가 아니다.
-  \#!는 셔뱅(shebang)이라고 부르고, #! 다음에 오는 문구를 실행한다. 예를 들어 #!/bin/bash라고 쓰면 스크립트가 실행되면 /bin/bash부터 실행하게 된다. 따라서 /bin/bash 이후에 나오는 명령어는 bash를 이용해서 해석할 것이라는 의미이다.



<br>

<br>

# 쉘 스크립트 실행하기

디렉토리에서 실행해야 함

-  ./sds.sh → 실행전에 실행권한 필요 O
-  bash ./sds.sh → 실행전에 실행권한 필요 X

<br>

<br>

# Echo

-  `echo`는 컴퓨터의 터미널 또는 명령 프롬프트에서 사용되는 명령어로, 주어진 텍스트를 화면에 출력하는 데 사용된다.

`echo 명령어`는 주로 스크립트 파일에서 메시지를 출력하거나 변수의 값을 표시하고 디버깅할 때 유용하게 사용된다.

`echo 명령어`는 개행을 포함한채 출력 ↔ `printf 명령어`는 개행을 포함하지 않고 출력한다.

echo 명령어 - echo $PATH →  환경변수 보기 - echo $0 , echo $SHELL → 사용중인 쉘 확인





<br>

<br>

# 기본 실행 방법 (Tutorial)

1.파일 생성

```bash
➜  ~ cd Desktop #Desktop 들어가기
➜ mkdir shelltest #빈 디렉토리 생성
➜ cd shelltest #생성한 디렉토리 들어가기
➜ vim test1.sh #test1 이라는 파일 생성
```

<img src="{{site.url}}/images/2024-07-03-Shell Script/Untitled.png" style="zoom:40%;" />

<br>



2.기본 스트립트 작성

-  i로 insert모드에 진입, ESC눌러 일반모드, :wq 를 통해 저장 및 종

<img src="{{site.url}}/images/2024-07-03-Shell Script/Untitled 1.png" style="zoom:40%;" />

<br>



3.권한부여 및 실행

```bash
➜ chmod +x test1.sh #파일에 실행 권한 부여
➜ ls #디렉토리 목록 확인
test1.sh

➜  ./test1.sh #스크립트 실행
```

<img src="{{site.url}}/images/2024-07-03-Shell Script/Untitled 2.png" style="zoom:40%;" />



<br>

<br>

# 쉘 변수

>  [참고 문헌 : 위키독스 리눅스 쉘 스크립트](https://wikidocs.net/163505)

## 변수 규칙

1. 리눅스의 모든 변수는 문자열(string)으로 취급한다.
2. 변수 이름은 대소문자를 구분한다.
3. 변수에 값을 대입할 때는 ‘=’좌우에 공백이 없어야 한다.
4. 변수에 들어간 문자를 출력하려면 변수 앞에 $를 붙이고 echo 명령어를 출력하면 된다.

```bash
#! /bin/bash

a='hello' #띄어쓰기 주의
b='world'

echo $a #hello
echo $b #world
echo $a $b! #hello world!
```



<br>

<br>

## 변수 숫자 계산 규칙(expression)

1. 변수에 대입한 값은 모두 문자열(string)으로 취급한다.
2. 변수에 들어있는 값을 숫자로 해서 사칙연산을 하려면 expr을 사용해야 한다.
3. 수식에 괄호 또는 곱하기를 사용하려면 그 앞에 반드시 역슬래시를 붙여야 한다.
4. 사칙연산 기호 양옆은 공백을 넣어야 한다.

```bash
#! /bin/bash

a=100
b=50

echo a = $a 
echo b = $b
echo a + b = $a + $b
expr $a + $b
echo a + b = $(expr $a + $b)
```

<img src="{{site.url}}/images/2024-07-03-Shell Script/Untitled 3.png" style="zoom:40%;" />



<br>



<aside> 💡 문제1. a, b 의 곱셈   (a=100,b=5)

</aside>

```bash
#! /bin/bash

a=100
b=50

expr $a \\* $b
```

<br>



<aside> 💡 문제2. (a+ 200)∗b   (a=100,b=5)

</aside>

```bash
#! bin/bash

a=100
b=5

expr \\($a + 200 \\) \\* $b
```





<br>

<br>



## 파라미터 변수

1. 파라미터 변수는 0,1,$2, …의 형태를 가진다.
2. 전체 파라미터는 $*로 표현한다.

```bash
#! bin/bash

num1=$1
num2=$2
num3=`expr $num1 + $num2`
num4=$(expr $num1 + $num2)

echo "$num1 + $num2 = $num3"
```



<br>

<br>

# 조건문

문자열 비교

1. “문자열”==”문자열2”
2. “문자열”!=”문자열2”

```bash
#! bin/bash

num1=$1
num2=$2
if [ $num1 -eq $num2 ]; then
  echo "$num1 = num2."
else
  echo "$num1 != $num2."
fi
```

<br>

<br>



숫자열 비교

| 코드            | 의미                                     |
| --------------- | ---------------------------------------- |
| 숫자1 -eq 숫자2 | 두 숫자가 같은면 true(=)                 |
| 숫자1 -eq 숫자2 | 두 숫자가 같지 않으면 false(!=)          |
| 숫자1 -gt 숫자2 | 숫자1이 숫자2보다 크면 true(>)           |
| 숫자1 -ge 숫자2 | 숫자1이 숫자2보다 크거나 같으면 true(>=) |
| 숫자1 -lt 숫자2 | 숫자1이 숫자2보다 작으면 true(<)         |
| 숫자1 -le 숫자2 | 숫자1이 숫자2보다 작거나 같으면 true(<=) |
| !숫자1          | 숫자1이 아니라면 true(not)               |

```bash
#! bin/bash

num1=$1
num2=$2

if [ $num1 -eq $num2 ]; then
  echo "$num1 == $num2"
elif [ $num1 -gt $num2 ]; then
  echo "$num1 > $num2"
elif [ $num1 -ge $num2 ]; then
  echo "$num1 >= $num2"
elif [ $num1 -lt $num2 ]; then
  echo "$num1 < $num2"
elif [ $num1 -le $num2 ]; then
  echo "$num1 <= $num2"
fi
```



<br>

<br>

# 반복문

```bash
for 변수 in 값의 범위
do 
  반복할 문장
done

```

```bash
#! bash/bin

for i in {1..10}
do
  echo $i
done
```

<img src="{{site.url}}/images/2024-07-03-Shell Script/Untitled 4.png" style="zoom:40%;" />

<br>

<br>

# LINUX 핵심 명령어

<br>

## sh파일 내용 확인

-  cat file.txt

<br>

## 프로세스 확인

-  ps -ef
   -  소유자 정보와 함께 full format으로 볼 수 있다. (실행중인 프로세스)
   -  ps -ef | grep [pid] : 해당 프로세스만 보기
-  ps -w
-  man ps
   -  ps와 관련된 명령어 볼 수 있다.
-  ps aux | grep [pid]
   -  실행중인 프로세스 소유자 정보와 함께 정보 나옴
-  ps -p [pid]
   -  해당 프로세스의 간단한 정보
-  ps -u [사용자명]
   -  특정 사용자의 프로세스 정보

<br>

## 파일 삭제

-  rm [파일이름.확장자]

<br>

## 현재 directory 경로

-  **pwd**



<br>



## 파일 복사

-  cp [복사파일] [새로운 파일 이름]

<br>

## 파일 출력

-  head -n 줄갯수 [파일이름] : 앞의 n개 줄 출력
-  tail -n 줄갯수 [파일이름] : 뒤의 n개 줄 출력

<br>



## 파일 이동 , 이름 변경

-  mv [전 파일] [후 파일 디렉토리 or 파일 이름]







<br>

<br>

<br>

<br>





### 참고 문헌

https://gr-st-dev.tistory.com/236

https://techbukket.com/blog/shell-script-guide

https://losskatsu.github.io/os-kernel/bash/#11-사용법

https://inpa.tistory.com/entry/LINUX-쉘-프로그래밍-핵심-문법-총정리
