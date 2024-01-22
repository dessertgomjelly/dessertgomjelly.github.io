---
layout: single
title: "[LG Aimers] 5-4. Transformer"
categories: LG_Aimers
tag: [AI, 인공지능, Deep Learning, CNN]
use_math: true #수학 공식 가능하게
sidebar:
    nav: "counts"




---



<style>
  body {
    font-size: 16px; /* 폰트 사이즈 조절 */
  }
</style>




**[공지사항]** [해당 내용은 LG에서 주관하는 LG Amiers : AI 전문가 과정 4기 교육 과정입니다.]  강의를 듣고 이해한 내용을 바탕으로 직접 필기한 내용입니다. 
[LG AI](https://www.lgaimers.ai/)
{: .notice--danger}

<br>
<br>

# **5-4. 딥러닝(Deep Learning)**

-  교수 : KAIST 주재걸 교수 
-  학습목표
   -  Neural Networks의 한 종류인 딥러닝(Deep Learning)에 대한 기본 개념과 대표적인 모형들의 학습원리를 배우게 됩니다.
   -  이미지와 언어모델 학습을 위한 딥러닝 모델과 학습원리를 배우게 됩니다. 



<br>

<br>

## Transformer 모델의 동작 원리

-  Transformer는 주로 번역과 같은 자연어 처리 작업에 쓰이는 신경망으로, 단어 간 관계를 잘 이해하고 효과적으로 특징을 추출한다. Self-Attention과 다중 헤드 어텐션을 중심으로, 인코더와 디코더로 구성되며, 단어의 순서 정보를 위치 인코딩으로 유지한다. 기존의 RNN이나 LSTM보다 높은 성능을 보인다.
-  최근 굉장히 많이 각광받고 있는 모델이다.
-  기존에 배웠던 Seq2Seq with attention model의 좀 더 나은 개선판이라고 생각 할 수 있다.



-  `그렇다면 기존의 Seq2Seq model에서는 어떤 이슈가 있을까?`
   -  Long-term Dependency 이슈가 있다.
      -  Forward propagation
         -  주어진 시퀀스를 잘 encoding 해서 정보를 축적할 때 $h_3$라는 Hidden state vector에서 예전 정보를 잘 담겨 있어야만 한다. 
      -  Backpropagation(역전파)
         -  모델 학습과정에서도 마지막 time step 의 Hidden state vector인 $h_L$에서부터 여러 time step에 걸쳐서 gradient 정보가 변질되는 문제점들이 있다.

<img src="/Users/dessert_gomjelly/Desktop/깃허브블로그/dessertgomjelly.github.io/images/2024-01-22-LG Aimer Module 5-4/image-20240122171731122.png" alt="image-20240122171731122" style="zoom:50%;" />



-  따라서 어떤 time step 에서든 바로바로 접근해서 필요한 정보를 잘 축적 하도록 Attention model을 이용한다.