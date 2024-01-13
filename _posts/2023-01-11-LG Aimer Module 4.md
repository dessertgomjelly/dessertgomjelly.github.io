---

layout: single
title: "[LG Aimers] 4-1. Supervised learning (classification/regression)"
categories: LG_Aimers
tag: [AI, 인공지능, Machine Learning, Regression]
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



# **4-1. 지도학습(분류/회귀)**

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

<img src="{{stie.url}}/images/2023-01-11-LG Aimer Module 4/image-20240111231541115.png" alt="image-20240111231541115" style="zoom:67%;" />

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

<br>

-  세타와 X의 선형 결합을 통해 아래식과 같이 Score을 계산할 수있다.
   -  Score값과 Y의 차이를 통해 Loss 를 통한 Matirx를 구할 수 있다.
   -  최적화 파라미터 세타는 이러한 Cost function을 가장 최소화 하는것이다.



<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112160700057.png" alt="image-20240112160700057" style="zoom: 67%;" />



-  Soultion:
   -  Gradient descent를 통해 iterative(반복적)하게 최적의 파라미터 세타를 찾는다.



## Gradient descent(경사 하강법)

-  Gradient
   -  함수를 미분하여 얻는 term으로 해당 함수의 변화정도를 표현하는 값
-  Gradient decent
   -  Gradient 가 0인 지점까지 반복적으로 세타를 바꿔나가면서 탐색을 한다.
      -  해당 지점에서 기울기가 가장 큰 방향으로 간다.

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112161849777.png" alt="image-20240112161849777" style="zoom:50%;" />

<br>

### Local optimum VS global optimum

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112162455585.png" alt="image-20240112162455585" style="zoom: 67%;" />

-  지역 최적해(Local Minimum)는 최적화 문제에서 함수가 국부적으로 최소값을 가지는 지점을 나타낸다.
-   경사 하강법과 같은 최적화 알고리즘이 사용되는 경우, 이 알고리즘이 수렴하는 지점이 지역 최적해일 수 있다.

-  지역 최적해는 전체 함수 공간에서 최소값이 아닐 수 있으며, 이는 전역 최적해와 구별된다.

-  경사 하강법 등의 최적화 알고리즘에서는 지역 최적해에 갇히지 않도록 여러 가지 방법이 사용됩니다. 
   -  예를 들어, 다양한 초기값에서 출발하여 여러 번의 최적화를 수행하고 결과를 비교하거나, 
   -  학습률을 조절하거나, 
   -  더 복잡한 최적화 알고리즘을 사용하는 등의 전략이 존재한다.



## Quiz

Q. 선형 회귀 분석에서는 입력 특성을 수정하여 솔루션을 해석할 수 있습니다. 점수는 입력 특성과 가중치의 선형 조합으로 계산됩니다. 무게
최종 출력에 대한 입력 기능의 중요성을 설명합니다.

A . 맞습니다.



<br>

Q. 선형 회귀에서 가설은 반드시 학습 가능한 매개변수의 선형 형태일 필요는 없습니다.

A. 선형 회귀에서 가설은 꼭 선형 형태일 필요가 없습니다. 입력 특징을 변환하거나 다항식 특징을 추가함으로써 비선형성을 도입할 수 있습니다.

<br>

<br>



# *CHAPTER 2. Gradient Descent*



<br>

<br>





## Gradient descent algorithm (경사 하강법)

-  우리의 목적은 다음과 같은 손실함수를 최소화하는 파라미터를 찾는 것이다.

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112163321268.png" alt="image-20240112163321268" style="zoom:50%;" />

-  이에 대한 방법론으로 Gradient Decent 알고리즘에서는 다음과 같은 outline을 따른다.
   -  1.  Initial parameters(초기  파라미터) 세타0, 세타1로 부터 시작한다.
      2.  이 값들을 지속적으로 최소로 하는 지점까지 변화하도록 하는 목적이다.
      3.  함수의 변화량이 가장 큰 (기울기가 가장 큰) 방향으로 파라미터를 업데이트 한다. 이때 step size 는 파라미터 업데이트의 변화 정도를 조정하는 값으로 **하이퍼 파라미터** 이다.
          -  알파는 사전의 정의된 값이다.
          -  세타는 우리가 구하고자 하는 값이다.

<br>

<br>

-  다음과 같은 3개의 그래프를 비교해보자.
   -  첫번째 그래프의 경우 알파값에 적당한 경우이다.
      -  어느정도 빠르게 수렴하면서 안정적이다.
   -  두번째 그래프의 경우 알파값이 매우 적은 경우이다.
      -  수렴속도가 굉장히 천천히 떨어진다.
      -  하지만 수렴하는 형태는 굉장히 안정적이다.
   -  세번째 그래프의 경우 알파값이 매우 큰 경우이다.
      -  최소의 지점을 찾기가 어렵고 발산하는 형태이다.
      -  Loss또한 오히려 늘어나고 있다.

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112182424101.png" alt="image-20240112182424101" style="zoom:67%;" />

<br>

<br>



## Batch gradient descent algorithm

-  앞에서와 같은 Gradient desecent algorithm을 Batch gradient descent algorithm라고 표현한다.

-  비록 Local optimum(지역 최적해) 에는 취약하지만, 어느정도 수렴해 가는 것을 알 수 있다.

   ![image-20240112182923703]({{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112182923703.png)

   <br>

-  하지만 이 알고리즘은 단점이 있다.

   -  위의 수식을 보면 세타를 업데이트 하는 과정에서 전체 샘플 m에 대해 모두다 고려해야한다는 것이다.
   -  이러한 단점을 극복하기 위해서 m을 극단적으로 줄인 알고리즘을 Stochastic Gradient Descent(확률적 경사하강법)라고한다.
      -  $SGD : m = 1$
      -  빠르게 iteration을 할 수 있다는 장점이 있지만, 결국 각 샘플에 대해 개별적으로 계산을 하기때문에 noise의 영향이 있다.



<br>

<br>

## Momentum

-  지역 최적해에 취약한 Gradient decent algorithm을 보완하게 위한 알고리즘이다.
-  과거의 Gradient가 업데이트 되어오던 방향 및 속도를 어느정도 반영해서 현재 포인트에서 Gradient가 0이되더라도 계속해서 학습을 진행 할수 있는 동력을 제공하는 것이다.
-  Momentum은 현재의 gradient뿐만 아니라 과거의 gradient 업데이트 정보도 고려하여 이전 방향과 속도를 유지하려는 개념이다.

<br>

<br>



## Nesterov Momentum

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112201421974.png" alt="image-20240112201421974" style="zoom:67%;" />

-  Momentum update
   -  다음 그림을 보면 현재의 gradient step과 momentum step을 고려해서 actual step (실제 스텝)을 벡터의 합으로써 구한다.
   -  정리하자면 gradient와 momentum으로 actual step을 구한다.
-  Nesterov Momentum update
   -  미리 momentum step 만큼 이동한 지점에서 "lookahead" gradient step을 계산하여 이 두개의 스텝으로 actual step을 구한다.
   -  정리하자면 momentum step과 이 미리 예측된 위치에서의 "lookahead" 기울기를 이용하여 actual step을 구한다.



<br>

<br>

## AdaGrad(Adaptive Gradient Descent)

-  각 방향으로의 학습률을 적응적으로 조절하여 학습 효율을 높이는 경사하강법의 알고리즘이다.
-  AdaGrad의 수식을 살펴보자
   -  먼저 r은 그래디언트의 제곱이 계속해서 누적으로 더해지기 때문에 r값은 커진다.
   -  또한 r은 파라미터의 분모에 들어가기때문에 델타 세타의 값은 계속해서 작아진다.
   -  이 말은 그래디언트의 누적 값이 커진다는 말은 이미 학습이 많이 진행 되었다는 뜻이기 때문에 델타 세타의 값은 그만큼의 수렴속도를 줄여야하기때문에 작아진다.

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112202550261.png" alt="image-20240112202550261" style="zoom:50%;" />

**'학습률이 작아지게 되면 어떻게 되나요?'**

-  학습이 일어나지 않게 된다.
   -  이러한 방식을 수정한 것이 RMSProp algorithm이다.

<br>

<br>

## RMSProp algorithm

-  수식에서 볼 수 있다시피 있다시피 RMSProp 방식은 그래디언트의 제곱을 그대로 곱하는게 아니라 기존에 있던 $r$에 *ρ*(Decay factor는 지수 감소(exponential decay)에서 사용되는 용어) 값을 곱하게 되고 1-*p*를 그래디언트의 제곱에다가 곱함으로써 과거의 $r$만큼의 *p*를 곱해서 어느정도 조절하게 된다.

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112203208007.png" alt="image-20240112203208007" style="zoom:67%;" />

<br>

<br>

## Adam

-  앞으로 머신러닝 또는 딥러닝을 공부 하면서 가장 많이 만나게 될 알고리즘이다.

-  Adma은 RMSProp 와 Momentum의 혼합 방식이다.

-  이 알고리즘의 순서는 다음과 같다.

   -  1.  첫번째로 모멘텀을 계산한다. 이 모멘텀은 s와 같은 형태로 구성되어있다. 

          $s=p_1⋅s+(1−p_1)⋅g^2$

   -  2.  두번째로는 RMSProp방식으로 두번째 모멘텀을 계산하게 된다.

          $s=p_2⋅s+(1−p_2)⋅g^2$

   -  3.  그다음은 통계적으로 안정된 값을 위해 bias를 Correct 한다.

          <img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112204429141.png" alt="image-20240112204429141" style="zoom:50%;" />

   -  4.  마지막으로 파라미터를 업데이트 한다.

          <img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112204457656.png" alt="image-20240112204457656" style="zoom:50%;" />

<br>

<br>

## Model 과적합 문제

-  model이 지나치게 복잡하여, 학습 파라미터의 숫자가 많아서 제한된 학습 샘플에 너무 과하게 학습이 되는 것이다.
-  *입력 feature 의 숫자가 지나치게 많아진다고 하면 항상 좋은것일까?*
   -  아니다. 일부 입력변수들은 상호관련 있을수있다. 
   -  입력 개수가 많아지면 파라미터가 많아지게 되고 data의 개수 또한 많아진다.
   -  실제 환경에서는 데이터를 충분히 늘릴 수 없는 경우가 있다.
   -  이러한 문제를 해결할 수 있는 대표적 방법은 Regularization방식이다.



<br>

<br>



## Regularizaion(정규화)

-  복잡한 모델을 사용하더라도 학습 과정에서 모델의 복잡도에 대한 패널티를 줘서 모델이 오버피팅 되지 않도록 하는 방식이다.

-  수식을 살펴보면 MSE 부분을 fitting이라고 한다면 그 뒤의 수식은 세타 j값이 크면 클수록 늘어나게 되는 오류이다.

   -  모델의 입장에서는 가능한한 세타를 쓰지 않으면서 이 Loss 를 최소화하는 노력을 한다.

      <img src="{{site.url}}/images/2023-01-11-LG Aimer Module 4/image-20240112205757906.png" alt="image-20240112205757906" style="zoom:50%;" />

   -  이 정규화 항은 가중치가 커질수록 전체 손실 함수를 증가시키므로, 모델은 가중치를 작게 유지하려고 노력하게 된다. 이는 모델이 더 간단한 형태로 학습되도록 유도하여 오버피팅을 방지하는 역할을 한다.










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

## Cross-entropy Loss

-  Cross-entropy Loss는 Classification모델에서 가장 많이 사용되는 손실 함수이다.

-  <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113163455866.png" alt="image-20240113163455866" style="zoom:50%;" />

   -  *y*는 실제 레이블의 확률 분포이다. (예: 실제로 고양이인 경우 [0, 1])

   -  *y^*는 모델의 예측 확률 분포이다. (예: 모델이 고양이라고 예측한 경우 [0.2, 0.8])

-  즉, 크로스 엔트로피는 두 확률 분포 간의 "차이"를 측정하는데, 이 거리가 작을수록 모델의 예측이 좋다고 판단된다. 이 학습의 목표는 이 크로스 엔트로피를 최소화하여 모델을 더 정확하게 만드는 것이다.

<br>
<br>

#### Sigmoid 

-  시그모이드 함수를 이용하면 score값을 매핑 할 수가 있다.

-  밑의 슬라이드를 보면 쉽게 이해가 된다.

   -  sigmoid함수에 따라 +방향으로 증가하게 된다면 1에 근사하게 되고 -방향으로 간다면 0에 근사하게 된다. 0에 근사하게 된다면 1/2 값을 갖게 된다.
   -  Score 실수값을 0부터 1사이의 값으로 매핑 할 수가 있는데 이를 **로지스틱 모델**이라고 한다.

   <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113164709798.png" alt="image-20240113164709798" style="zoom:50%;" />

<br>
<br>

## Multiclass classification

-  Binary classification 문제를 Multiclass classification 문제로 확장 할 수가 있다. 이것을 **One-VS-All** 방식으로 이해 할 수가 있다.
-  그림에서 볼 수 있듯이 3개의 Hyper plane을 그어서 Multiclass classification문제를 Binary classification문제로 풀 수 있게끔 할 수 있다.

 <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113165107432.png" alt="image-20240113165107432" style="zoom:50%;" />



  <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113165335784.png" alt="image-20240113165335784" style="zoom:50%;" />

-  A or not 에 대한 파라미터부터 C or not에 대한 파라미터까지 벡터로 정의한다면 다음과 같이 Score값의 형태가 나온다.
   -  이렇게 얻게된 Score값들에 시그모이드 함수를 사용하게되면 확률값으로 매핑할 수가 있게 된다.

<br>
<br>

# *CHAPTER 4. Advanced Classification*

<br>

<br>



## Margin

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113170150805.png" alt="image-20240113170150805" style="zoom:50%;" />

-  다음과 같은 그림에서 Hyper plane을 어떻게 긋느냐에 따라 new data의 분류가 정해지게 되며 성능 또한 달라진다.
-  이러한 문제를 해결 하는 방법은 SVM에서 중요한 Margin이라는 개념이다.



<br>

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113170436442.png" alt="image-20240113170436442" style="zoom:50%;" />

-  그림에서와 같이 hyper plane과 가장 가까운 positive sample과 negetive sample을 기준으로 점선을 긋는다.
-  Hyper plane과 이 둘 점선의 위치가 가장 동일한 구간이 최대 margin을 확보할 수있는 최적화 방식이다.

<br>

<br>



## Support Vector Machine

-  서포트 벡터 머신에서는 이러한 개념을 설명하기 위해서 서포트 벡터라는 것을 정의하게 된다.
   -  서프트 벡터는 positive, negetive sample 중에서 hyper plane과 가장 가까운 sample을 뜻한다.
   -  이 것은 성능을 결정하는 가장 중요한 Data Point이다.
   -  SVM의 목표는 이 마진을 최대화하는 결정 경계를 찾는 것이다.



-  Support Vector Machine에서는 다양한 최적화 방법을 사용한다.
   -  **Hard margin SVM**
      -  그림과 같이 Hyper plane과 서포트 벡터 사이의 공간에 어떠한 sample도 존재하지않는다.
      -  <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113171308971.png" alt="image-20240113171308971" style="zoom:50%;" />
   -  **Soft margin SVM**
      -  hard margin SVM과 달리 어느 정도의 error를 용인한다.
   -  **Nonlinear transform & kernel trick**
      -  SVM의 Linear한 환경에서 사용할 수 있다는 단점을 극복하기 위해 만들어졌다. 
      -  2차원의 sample을 좀 더 고차원으로 맵핑하는 함수를 이용한다.
      -  <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113171735209.png" alt="image-20240113171735209" style="zoom:50%;" />





<br>

<br>



## Hard Margin SVM

-  가설함수 h(x)가 0이 되는 부분이 Hyper plane이다. 
-  계산상의 편의를 위해 서포트 벡터들이 갖는 값을 각각 +1, -1이라고 생각해보자
   -  그렇다면 다른 samle들은 Positive의 경우 1보다 크고, Negetive의 경우 1보다 작게 된다.
   -  최종적으로 $y$와$(w^Tx+b)$를 곱하면 모든 샘플에 대해서 1보다 크거나 같은 경우가 나온다.
   -  이를 SVM에서의 Constraint(제약조건)이라고 말하게 된다.

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113171942233.png" alt="image-20240113171942233" style="zoom:50%;" />

-  다시 Margin으로 돌아와서 마진은 SVM에서 다음과 같다.
   -  positive와 negetive의 거리가 같기 때문에 *2/||w||* 를 최대화 하는 것이 목표이다.
   -  이 말은 즉 *||w||* 를 최소화 하는 것과 똑같은 말이다.

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113172541220.png" alt="image-20240113172541220" style="zoom:50%;" />

<br>

#### SVM Primal problem

-  *||w||*는<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113172957598.png" alt="image-20240113172957598" style="zoom:50%;" /> 과 같은 수식을 따른다. 그렇게 때문에 편의를 위해 제곱을 하고 결론적으로는 $||w||^2$을 최소화하는 것과 동일하다고 말할 수 있다.
-  또한 위에서 말했듯이 제약조건 $y(w^Tx+b)>=1$ , 이 두가지가 SVM의 Primal problem이다.!!

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113173322737.png" alt="image-20240113173322737" style="zoom:50%;" />

<br>

<br>





## ANN(Arifical neural network)

-  Non-linear classification model

-  ANN 또한 다음 그림에서 볼 수 있다시피 x와 파라미터의 선형결합을 통해 구한 Score값을 이용하게 된다. 하지만 ANN은 Non-linear한 구조를 가지고 있다. 그러한 연산이 Activation function에 의해서 이뤄지게 된다.

-  Score값을 Activation function의 입력으로 쓰면서 시그모이드와 함수와 같이 non-linear한 맵핑한 결과 만들어 내게 된다.

   <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113173827993.png" alt="image-20240113173827993" style="zoom:50%;" />



<br>



#### Activation functions

-  초기에는 시그모이드 함수를 사용했지만, 깊이있는 학습에 도움이 되지 않는다고 알려져있다.

-  따라서 ReLU와 같은 함수를 이용한다.

-  왼쪽의 시그모이드 함수의 경우 z값이 매우 커지거나 작아짐에 따라서 그래디언트가 굉장히 작아지게 되어서 학습이 진행됨에 따라 학습량이 점차 줄어드는 단점이 있다.

   -  따라서 그래디언트 값이 1로 유지되는 ReLU가 가장 많이 활용된다.

   <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113174423468.png" alt="image-20240113174423468" style="zoom:50%;" />

<br>

<br>



## Multilayer perceptron model (MLP)

-  Neural Network를 여러 개의 층으로 쌓은 것을 의미한다.

   <br>



### For Example : XOR

-  XOR 문제는 어떠한 하나의 Hyper plane을 그어도 효과적으로 분류 할 수 없게 된다. 그럼 어떻게 해결할 수 있을까?

<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113175021486.png" alt="image-20240113175021486" style="zoom:50%;" />

-  다음 슬라이드를 보면 쉽게 이해할 수 있다.
   -  (x1, x2)가 (0,0) 이라고 할때, w와 b가 나타나있으므로 각각 y1,y2를 구할 수가 있다.
   -  y1,y2를 입력으로 넣고 출력을 구하게 되면 시그모이드 함수를 통해 XOR문제를 쉽게 구할 수가 있다.



<img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113175627788.png" alt="image-20240113175627788" style="zoom:99%;" />



-  최종적으로 구한 답이다.

   <img src="{{site.url}}/images/2023-01-12-LG Aimer Module 4-2/image-20240113175847816.png" alt="image-20240113175847816" style="zoom:99%;" />

<br>

<br>



# *CHAPTER 5. Ensemble*

<br>

<br>



## Ensemble Learning

-  Ensemble Learning은 이미 사용하고 있거나 개발한 알고리즘의 간단한 확장이다. 
-  Supervised learning task에서 성능을 올릴 수 있는 방법이다.
