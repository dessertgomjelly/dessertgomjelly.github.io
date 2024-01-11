---
layout: single
title: "[LG Aimers] Section 3-2. Intruduction to Machine Learning"
categories: LG_Aimers
tag: [AI, 인공지능, Machine Learning]
use_math: true #수학 공식 가능하게
sidebar:
    nav: "counts"
---

<style>
  body {
    font-size: 16px;
    display: flex;
    justify-content: center;
    align-items: center;
    height: 100vh;
    margin: 0; /* Body의 기본 마진 제거 */
  }
</style>


**[공지사항]** [해당 내용은 LG에서 주관하는 LG Amiers : AI 전문가 과정 4기 교육 과정입니다.] 
[LG AI](https://www.lgaimers.ai/)
{: .notice--danger}

<br>
<br>

# **Section 3. Machine Learning 개론**

-  교수
   -  서울대학교 김건희
-  학습목표
   -  본 모듈은 Machine Learning의 기본 개념에 대한 학습 과정입니다. ML이란 무엇인지, Overfitting과 Underfitting의 개념, 최근 많은 관심을 받고 있는 초거대 언어모델에 대해 학습하게 됩니다.

<br>

<br>

# **CHAPTER 2. Bias and Variance**

<br>

<br>

## Generalization

-  일반화란 기계학습의 능력이다.
   -  기계학습이 학습한 데이터보다 새로운 데이터에 대해서 잘 하는 것이 중요하다. → 일종의 모순이다.
   -  일반화 능력은 Overfitting(과적합)과 개념이 밀접하다.
-  검정색 별 부분을 학습 Data라고 할 때
   -  왼쪽 그림의 경우 복잡한 함수로 구성되어 있으며 새로운 데이터에 대한 영역이 Up,down이 심하다.
   -  오른쪽 그림의 경우 학습된 부분들이 부드럽기 때문에 새로운 영역에 대해서도 잘본다.
      -  따라서 실제 Y값과 함수 값의 Training Error 가 큼에도 불구하고 이 함수를 활용한다.

<img src="/images/2023-01-11-LG Aimer Module 3-2/image-20240111185725653.png" alt="image-20240111185725653" style="zoom:50%;" />

<br>

<br>

## Training Data vs Test Data

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 3-2/image-20240111185735888.png" alt="image-20240111185735888" style="zoom:50%;" />

1. Universal Set (전체 집합):
   -  Universal Set은 일반적으로 데이터셋이나 분석 대상의 전체 집합을 나타낸다.
2. Training Set (훈련 집합):
   -  Training Set은 기계 학습 모델을 훈련시키기 위한 Universal Set의 Samling이다. 이것은 입력-출력(이사진은→고양이) 쌍으로 이루어져 있으며, 모델은 입력과 출력 간의 패턴과 관계를 학습한다.
3. Test Set (시험 집합):
   -  Test Set은 Training Set과 별도로 유지되는 Universal Set의 또 다른 부분이다. 모델 훈련 후에는 모델을 테스트 세트에서 평가하여 새로운, 보지 못한 데이터에 대한 성능을 평가하고 일반화 능력을 추정한다.

<br>

<br>

## Generalization Error

-  Loss를 하나의 숫자로 요약한다. Loss는 확률 분포를 따르는데  모델이 예측한 값과 실제 정답 간의 차이를 측정하여 모델의 성능을 평가하는 것이다. 

-  Generalization Error(일반화 오차) 를 구하는 이 수식을 보면 예측값 h(x), y에 대한 Loss를 E라는 숫자로 표현한다. 

   <img src="{{site.url}}/images/2023-01-11-LG Aimer Module 3-2/image-20240111185746067.png" alt="image-20240111185746067" style="zoom:50%;" />

-  **과소적합 (Underfitting):** 
   -  일반화 오차 < 훈련 오차. 
-  **과적합 (Overfitting):**
   -   일반화 오차 > 훈련 오차. 

-  일반적으로 과소적합이 최악의 경우이다. "학습도 제대로 못 시켰네" 라는 기계학습의 기본조차도 못한것처럼 이야기 하는 경우가 많다. 따라서 우선적으로 과적합을 목표로 기계학습을 하면 된다.

<br>

<br>

## Model's Capacity

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 3-2/image-20240111185711058.png" alt="image-20240111185711058" style="zoom:50%;" />

-  다음과 같이 7개의 데이터를 fit 한다고 가정해보자.
   -  선형함수 , 2차함수, 9차 함수 순으로 fitting을 한다고 가정한다면.

-  선형함수
   -  데이터의 굴곡이 있을때 선형함수를 사용한다면 과소적합이 날 수 밖에 없다. Training Error를 줄일 수 가 없다.
-  9차함수
   -  복잡한 함수를 쓰면 Training Error 는 무조건 작아진다. 즉 Capacity가 늘어날 수록 무조건 작아진다. 
   -  하지만 너무 복잡한 모델을 쓰면 데이터가 없는 부분의 굴곡이 엄청나게 심하다. 따라서 과적합이 일어날 수 있다.

<br>

-  Training Error 는 복잡도를 높이면 높을수록 줄어든다.
-  하지만 기계학습의 목적은 Training Error를 줄이는게 아니라 일반화 Error를 최소화하는 것이다.
-  따라서 파란색 보다는 녹색 그래프가 최소가 되는 지점을 찾아야한다.
   -  Traning Error는 학습과정에서 쉽게 볼 수 있지만 일반화 Error는 쉽게 볼 수 없다.
      -  **** 따라서 Cross Validation등의 테크닉을 써서 일반화 Error를 예측한다.**** 

<img src="{{site.url}}/images/2023-01-11-LG Aimer Module 3-2/image-20240111190722024.png" alt="image-20240111190722024" style="zoom:50%;" />


## 규제화 (Regularization)

1. **Bias/Variance Decomposition (편향/분산 분해)**
   -  편향은 모델이 실제 값과 얼마나 떨어져 있는지를 나타낸다. 낮은 편향은 모델이 데이터를 잘 예측한다는 것을 의미한다.
   -  분산은 데이터를 다르게 샘플링할 때 모델이 얼마나 변하는지를 나타낸다. 낮은 분산은 모델이 안정적이라는 것을 의미한다.
2. **Trade-off between Bias and Variance (편향과 분산 간의 균형)**
   -  모델 복잡도를 늘리면 분산은 증가하고 편향은 감소하는 경향이 있다. 
   -  즉, 모델이 데이터에 더 잘 적합되지만, 과적합의 위험이 있다.
   -  둘 다 낮을 수록 좋기 때문에 이 둘의 균형이 중요하다.
3. **Overfitting vs Underfitting (과적합 대 과소적합)**
   -  높은 분산은 모델이 데이터에 과하게 적합되어 새로운 데이터에 대한 일반화 성능이 떨어지는 과적합을 나타낸다.
   -  높은 편향은 모델이 데이터에 부적합하여 훈련 데이터에서도 성능이 낮은 과소적합을 나타낸다.
4. **Weight decay(가중치 감쇠)**
   -  가중치 감쇠는 모델이 너무 복잡하지 않게 유지하면서도 중요한 특징을 학습하도록 도와주는 규제화 방법이다. 이를 통해 모델의 일반화 성능을 향상시킬 수 있다.

