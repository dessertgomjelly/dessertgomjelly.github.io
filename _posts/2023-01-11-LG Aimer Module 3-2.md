# module 3-2

```
layout: single
title: "[LG Aimers] Section 3-2. Intruduction to Machine Learning"
categories: LG_Aimers
tag: [AI, LG, LG_Aimers, 인공지능, ML, Machine Learning]
use_math: true #수학 공식 가능하게
```

<style> body { font-size: 16px; /* 폰트 사이즈 조절 */ } </style>

**[공지사항]** [해당 내용은 LG에서 주관하는 LG Amiers : AI 전문가 과정 4기 교육 과정입니다.] [LG AI](https://www.lgaimers.ai/) {: .notice--danger}

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

<img src="/Users/dessert_gomjelly/Desktop/깃허브블로그/dessertgomjelly.github.io/images/2023-01-11LG Aimer Module 3-2/image-20240111183454963.png" alt="image-20240111183454963" style="zoom:50%;" />

<br>

<br>

## Training Data vs Test Data

<img src="/Users/dessert_gomjelly/Desktop/깃허브블로그/dessertgomjelly.github.io/images/2023-01-11LG Aimer Module 3-2/image-20240111183532605.png" alt="image-20240111183532605" style="zoom: 33%;" />

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
-  <img src="/Users/dessert_gomjelly/Desktop/깃허브블로그/dessertgomjelly.github.io/images/2023-01-11LG Aimer Module 3-2/image-20240111183551688.png" alt="image-20240111183551688" style="zoom:50%;" />

-  **과소적합 (Underfitting):** 
   -  일반화 오차 < 훈련 오차. 
-  **과적합 (Overfitting):**
   -   일반화 오차 > 훈련 오차. 

-  일반적으로 과소적합이 최악의 경우이다. "학습도 제대로 못 시켰네" 라는 기계학습의 기본조차도 못한것처럼 이야기 하는 경우가 많다.