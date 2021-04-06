---
title: Mutabilidade e um de seus problemas
date: "2017-04-12T00:00:00.000Z"
description: "Quando você está programando Orientado a Objeto e não aplica alguns principios como SOLID você pode ter alguns problemas que são não existiria se você estiver usando imutabilidade."
---

Quando você está programando Orientado a Objeto e não aplica alguns principios como SOLID você pode ter alguns problemas que são não existiria se você estiver usando imutabilidade.

## Disclamer

Não estou falando que OOP não serve para nada e que você deveria abandonar de estudar os desgin patterns baseados no OOP, muito menos que FP (Functional Programming) é a solução para tudo, apesar de eu gostar muito de FP, tenho estudado muito sobre OOP, algo que tenho notado é a dificuldade de se entender os conceitos e a aplicar da forma correta. Coisa que em FP é bem mais simples de se entender. Só lembrando também, isso é só minha opinião sobre o assunto, fique a vontade para discutir sobre o assunto.

## Caso:

O caso que vou relatar aconteceu em um projeto no qual fiz parte e a stack era Java para Android.
O Problema:

Quando você tem um objeto e compartilha o mesmo objeto dentro da classe você compartilha o mesmo local da memoria e se em uma parte do código você modificar esse objeto para null pode acabar dando crash no seu app por que você vai usar um método desse objeto.

## Como Resolver?

Uma das soluções é você abandonar OOP e ir para FP, ou você usa o principio de responsabilidade unica para fazer um codigo um pouco mais decente, como eu deveria ter feito desde o começo, mas não fiz.

## Conclusão:

Quando você tem que usar um objeto em varias partes de uma classe o melhor a se fazer é você usar os metodos dele para que não tenha uma dor de cabeça no futuro assim como eu tive.
Caso não tenha concordado com algum ponto, comente..