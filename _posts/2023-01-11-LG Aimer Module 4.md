---
layout: single
title: "[LG Aimers] 4-1. 지도학습(분류/회귀)"
categories: LG_Aimers
tag: [AI, 인공지능, Machine Learning, Linear Regression]
use_math: true #수학 공식 가능하게
sidebar:
    nav: "counts"

---

<style>
  body {
    font-size: 16px; /* 폰트 사이즈 조절 */
  }
</style>






**[공지사항]** [해당 내용은 LG에서 주관하는 LG Amiers : AI 전문가 과정 4기 교육 과정입니다.] 
[LG AI](https://www.lgaimers.ai/)
{: .notice--danger}

<br>
<br>



# **Section 4. 지도학습(분류/회귀)**

-  교수 : 이화여자대학교 강제원 교수
-  학습목표
   -  Machine Learning의 한 부류인 지도학습(Supervised Learning)에 대한 기본 개념과 regression/classifiation의 목적 및 차이점에 대해 이해하고, 다양한 모델 및 방법론을 통해 언제 어떤 모델을 사용해야 하는지, 왜 사용하는지, 모델 성능을 향상시키는 방법을 학습하게 됩니다.



<br>
<br>

# *CHAPTER 1. Linear Regression*

<br>

<br>

## Linear models

-  Hypothesis 함수(가설함수) H가 입력 feature와 모델 파라미터의 linear conbination으로 구성된 모델이다.

-  수식을 보면 세타와 x의 내적연산으로 나타 낼 수 있다. 

   <img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240111230203273.png" alt="image-20240111230203273" style="zoom:50%;" />

-  이 모델에서 유의점은 선형 모델이라고 해서 반드시 입력 변수의 선형일 필요는 없다.

-  모델이 단순하기 때문에 성능이 높지 않더라도 다양한 환경에서 안정적인 성능을 제공할수 있다.
   -  Regression과 Classification에서 둘 다 사용 가능하다.

<br>

-  입력 데이터로 메일 주소 x를 받았다고 할 때 x로부터 여러 feature를 뽑는 과정
   -  입력 feature로 부터 세타와의 linear combination을 가지고 hypothesis함수를 구성할 수 있다. 
   -  x 는 각 feature를 의미하고 세타는 모델의 파라미터(가중치)를 의미한다.

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240111230911590.png" alt="image-20240111230911590" style="zoom:67%;" />

<br>

<br>



## Linear regression framework

-  Linear regression은 주어진 입력에 대해 출력과의 선형적인 관계를 추론하는 문제이다.
-  밑의 그림 처럼 3을 input으로 넣었을 때 에측 결과 2.71 이 나오게 된다.

<img src="/Users/dessert_gomjelly/Desktop/깃허브블로그/dessertgomjelly.github.io/images/2023-01-11-LG Aimer Module 4/image-20240111231541115.png" alt="image-20240111231541115" style="zoom:67%;" />

-  Linear regression의 절차
   -  1.  어떤 predictor를 이용할 것인가?
          -  Hypothesis class 를 정의해야한다.
          -  위와 같은 경우는 모델 파라미터가 2개이다. (offset, 입력변수 1개)
   -  2.  어떤 손실 함수를 사용해야할까?
          -  보통 선형 회귀 모델에서는 **Mean Squared Error(MSE)**를 사용한다.
      3.  어떻게 파라미터를 구할까?
          -  **Gradient descent algorithnm**
          -  Normal equation



<br>

<br>

## Parameter Optimization

-  앞서 말했듯이 선형 회귀 모델의 경우 동일하게 절차 1,2번을 따른다. 따라서  Linear regression의 3번째 "어떻게 파라미터를 구할까?" 에 대해서 알아보겠다.
-  모델 파라미터가 달라짐에 따라서 주어진 data에 fitting 하는 과정에서 오차가 발생하게 될것이다.

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240111232544120.png" alt="image-20240111232544120" style="zoom:50%;" />



<br>

-   다음은 모델 파라미티가 달라짐에 따른 손실함수에 대한 그래프이다.
-  우리의 목적은 이러한 손실함수를 최소화 하도록 하는 모델 파라미터 세타0, 세타1을 구하는 것이다.  그 지점은 그림에서 가장 오목한 부분이다.

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240111232659614.png" alt="image-20240111232659614" style="zoom:50%;" />



<br>

<br>

## 파라미터 최적화

-  ""어떻게 파라미터를 구할 수 있을까?" 에 대한 응답이 파라미터 최적화이다.
-  입력데이터를 matrix 형태로 표현한다면 다음과 같다.
-  <img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240111233049942.png" alt="image-20240111233049942" style="zoom: 33%;" />



<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240111234302597.png" alt="image-20240111234302597" style="zoom: 50%;" />







<br>

<br>

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240111234343798.png" alt="image-20240111234343798" style="zoom:50%;" />

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240111234406615.png" alt="image-20240111234406615" style="zoom:50%;" />

\
