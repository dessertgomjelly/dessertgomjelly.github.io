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

<img src="/images/2024-01-22-LG Aimer Module 5-4/image-20240122171731122.png" alt="image-20240122171731122" style="zoom:50%;" />



-  따라서 어떤 time step 에서든 바로바로 접근해서 필요한 정보를 잘 축적 하도록 Attention model을 이용한다.



<br>

<br>

## Self- attention model

-  앞 서 설명했던 attention model과 달리 정보를 찾고자 하는 주체와 정보를 꺼내가려고 하는 재료 vector를 같은 주체라고 생각해보자. 동작과정은 다음과 같다.
   1.  먼저 I 라는 단어의 vectort를 decoder의 특정 Hidden state vector처럼 사용한다. 
   2.  즉 자기자신과 내적, 옆에있는 $x2$, $x3$와 내적을 하여 유사도를 구한다.
   3.  유사도를 softmax 활성화 함수를 통과후 $x1$, $x2$, $x3$ 과의 가중합인 $h1$을 구한다.

<img src="{{site.url}}/images/2024-01-22-LG Aimer Module 5-4/image-20240122213509386.png" alt="image-20240122213509386" style="zoom:80%;" />

-  3가지 용도
   -  $q$(Query) : query vector 혹은 decoder hidden state vector처럼 사용 
   -  $k$(Key) : 쿼리 벡터와 유사도를 구할때 사용되는 재료 vector
   -  $v$(Value) : softmax 를 적용해서 가중합을 구하게 하는 재료 vector





<br>

<br>

-  `만약 x1, x2 두가지 단어를 합했을 때의 self-attention model을 생각해보자.`
   -  X는 x1, x2 vector를 합한 형태이며, 3가지 용도를 3가지 연산을 통해 얻을 수 있다.
   -  수식은 다음과 같다. <img src="{{site.url}}/images/2024-01-22-LG Aimer Module 5-4/image-20240122220130152.png" alt="image-20240122220130152" style="zoom:50%;" />
      -  $Q * K^T$는 Query와 Key의 내적을 의미하며, 이를 차원 $d$로 나누어준 것에 softmax 함수를 적용한다. 그리고 이렇게 얻은 가중치를 $Value$에 곱하여 최종 $Attention$ 값을 얻는다.

<img src="{{site.url}}/images/2024-01-22-LG Aimer Module 5-4/image-20240122215657179.png" alt="image-20240122215657179" style="zoom:50%;" />

<img src="{{site.url}}/images/2024-01-22-LG Aimer Module 5-4/image-20240122220645905.png" alt="image-20240122220645905" style="zoom:50%;" />



<br>

<br>

##  Transformer: Multi-head Attention

-  problem
   -  주어진 sequence의 각각의 입력 vector들을 encoding 할 때 어떤 특정한 $W_q$, $W_k$, $W_v$를 사용하면 하나의 유형으로 하나의 정해진 변환으로 attention module을 사용해서 sequence를 encoding하게 된다.
   -  특정 단어를 encoding할 때 이 사람이 어떤 행동을 했나, 어떤 시간에 했나 처럼 서로 다른 기준으로 정보를 추출해야 하는 필요성.
-  Solution
   -  선형 결합 set인  $W_q$, $W_k$, $W_v$ 를 여러개를 둔다. 각각의 set를 통해 변환된 Q, K, V를 사용해서 attention model을 통해 encoding 한다. 그 다음엔 각각의 set에 선형 변환을 사용해서 나온 output을 나중에 Concat하는 형태로 확장한다.
   -  attention을 여러개의 linear transformation set($W_q$, $W_k$, $W_v$)를 사용해서  attetion을 수행한다 해서 multi - head라고 한다.

<br>



-  각기 서로 다른 기준으로 encoding을 해서 만들어진 결과 vector $Z$ 이다

<img src="{{site.url}}/images/2024-01-22-LG Aimer Module 5-4/image-20240122222133904.png" alt="image-20240122222133904" style="zoom:50%;" />



<br>

<br>



-  차원의 방향으로 쭉 concat을 한다면 각 단어들을 다양한 기준에 의해서 encoding한 self-attention module의 output vector를 얻게 된다. 
   -  원하는 차원으로 만들기 위하여 추가적인 linear transformation을 거치게 된다.

<img src="{{site.url}}/images/2024-01-22-LG Aimer Module 5-4/image-20240122222728512.png" alt="image-20240122222728512" style="zoom:50%;" />



-  앞서 말했던 Long-term Dependency 이슈는 각각의 단어들이 query로 사용돼서 전체 sequence에 존재하는 각 단어들의 직접적으로 유사도를 구하고 거기서 유사도가 높은 단어를 직접적으로 꺼내갈 수 있다는 장점이 있다.
-  `하지만 self attention의 치명적인 단점은 무엇일까?`
   -  바로 Memory 요구량이다.
      -  <img src="{{site.url}}/images/2024-01-22-LG Aimer Module 5-4/image-20240122223326657.png" alt="image-20240122223326657" style="zoom:50%;" />







<br>

<br>