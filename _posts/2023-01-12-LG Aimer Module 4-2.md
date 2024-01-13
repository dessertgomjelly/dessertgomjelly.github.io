---
layout: single
title: "[LG Aimers] 4-2. Supervised learning (classification/regression)"
categories: LG_Aimers
tag: [AI, 인공지능, Machine Learning, Classification]
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





# **4-2. 지도학습(분류/회귀)**

-  교수 : 이화여자대학교 강제원 교수
-  학습목표
   -  Machine Learning의 한 부류인 지도학습(Supervised Learning)에 대한 기본 개념과 regression/classifiation의 목적 및 차이점에 대해 이해하고, 다양한 모델 및 방법론을 통해 언제 어떤 모델을 사용해야 하는지, 왜 사용하는지, 모델 성능을 향상시키는 방법을 학습하게 됩니다.



<br>

<br>

# *CHAPTER 3. Linear classification*

<br>
<br>

## Linear Classification

-  Linear regression 모델과 같이 다음과 같은 수식을 따른다.

   <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240112210948409.png" alt="image-20240112210948409" style="zoom:50%;" />

-  입력 freature *x* 와 그에 해당하는 파라미터셋 *w* 의 내적으로 구성되어있다.
   -  예측=*x*⋅*w*+*b*
-  가설 함수(hypothesis function)가 선형이라고 가정할 때, 이 함수의 결정 경계(decision boundary)는 데이터를 분리하는 초평면(hyperplane)이 된다.
   -  가설 함수 *h*(*x*)가 0보다 크면 양성 클래스(positive class), 0보다 작으면 음성 클래스(negative class)로 예측한다고 가정하면, 결정 경계는 가설 함수가 0이 되는 부분이다.
   -  결국 우리의 목적은 이러한 hyper plane을 구해서 우리의 data set에 있는 positive class 와 negetive class를 구분하는 것이다.

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240112211324966.png" alt="image-20240112211324966" style="zoom:50%;" />

-  Linear model 이 갖는 여러 장점 즉, 단순하며 해석 가능성이 있고 다양한 환경에서 일반적으로 안정적인 성능을 제공할 수가 있다.



<br>

<br>

## Linear classification framework

-  밑의 그림처럼 우리는 *h(x)*에 대하여 (2,0)이 들어갔을때 -1이 출력 될 것을 기대한다면 다음과 같은 과정을 따른다.

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113153605442.png" alt="image-20240113153605442" style="zoom:50%;" />

-  Linear classification의 절차
   
   -   1.  어떠한 예측 변수를 사용할것인가?
   -   2.  어떠한 손실 함수를 설정 할 것인가?
   
           -  Linear regression의 경우 MSE를 사용하지만
   
           -  Linear galssification의 경우 Zero-one loss, Hinge loss, Cross-entropy loss를 사용한다.
   -   3.  어떻게 파라미터를 최적화 할까?
   
       -  Gradient decent algorithm을 사용한다.
   

<br>
<br>

## Linear classification model

-  $h(x) = w_0 + w_1x_1+w_2x_2+w_2x_2$
   -  먼저 입력 변수와 파라미터의 곱으로 score를 계산한다. 이때 $w0$는 offset 이다.
      -  offset이란 상수항이다. 회귀 모델이 독립 변수가 0일 때의 기본값을 나타낸다.
-  score 값을 계산 한 이후에는 그 출력에 sign함수를 적용하게 된다. 

<br>



-  h(x)가 0보다 큰 구역, 작은 구역을 정의 하게 되는데, x가 0보다 크면 sign 함수에 의해 1, x가 0보다 작으면 -1 이 된다.

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113154818815.png" alt="image-20240113154818815" style="zoom:50%;" />

<br>
<br>

## Hypothesis class : which clssifier?

-  우리의 목적으로 되돌아와보자면 우리의 문제는 parameter w를 학습하는 것이다. w가 바뀜에 따라 샘플들의 판별 결과 또한 바뀌게 된다.
-  다음 수식 처럼 sign함수에 따른 결과가 바뀌게 되면 positive sample과 negetive sample의 결과가 뒤바뀌게 된다.

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113155340025.png" alt="image-20240113155340025" style="zoom:50%;" />

**그렇다면 Classification 문제에서 어떻게 Error를 판별할 수 있을까?**

-  하나의 예시로 Zero-One Loss를 생각 할 수 있다.
   -  이 losss는 내부의 logic을 판별하여 맞으면 0 틀리면 1을 출력하는 함수이다.

<br>

#### Zero-One Loss

-  Zero-One Loss 는 내부의 logic을 판별하여 맞으면 0 틀리면 1을 출력하는 함수이다.

-  $Loss([0,2],1,[0.5,1]) = 1[sign([0.5,1] * [0,2]) != 1] = 0$
   -  다음 수식을 살펴보자, $Loss([0,2],1,[0.5,1]) = 1$ 이 부분이 Zero- One Loss function이다. 하지만 내부의 값 둘을 내적한 것이 1이 아님을 알게 된다. $[0.5,1] * [0,2]) != 1$ 이다.  
   -  따라서 false, 0이 된다.

-  하지만 Zero-One Loss는 불연속성과 미분 불가능성 때문에 경사 하강법과 같은 최적화 알고리즘에서 사용하기 어려울 수 있다. 이러한 문제를 해결하기 위하여 classification에서 hinge Loss 를 사용한다.

<br>
<br>



## Hinge Loss

-  각 샘플에 대해 모델의 예측과 실제 레이블 간의 여유(margin)를 고려하는 분류 모델에서 사용되는 손실 함수 중 하나이다. 다음 수식을 살펴보자
-  $Hinge Loss(**w**,*b*,**x***i*,*y**i*)=max(0,1−*y**i*⋅(**w**⋅**x***i*+*b*))$
   -  *w*는 가중치(weight) 벡터,
   -  *b*는 편향(bias),
   -  *xi*는 입력 데이터의 특성(feature) 벡터,
   -  *y*i*는 실제 레이블,
   -  $y_i*(w*x_i+b)$는 모델의 예측과 실제 레이블 간의 여유(margin)를 나타낸다.
   -  이 수식에서는 0과 margin 사이의 max 값을 찾는 Loss이다. margin이 1보다 작으면 max값을 통해 손실 함수를 갖게 되고 margin이 1보다 크면 음수값이므로 max값은 0을 선택하게 되어 Loss는 0이된다.
   -  <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113162902934.png" alt="image-20240113162902934" style="zoom:50%;" />
-  결론적으로 margin이 크면 손실이 0이된다. 



<br>
<br>
