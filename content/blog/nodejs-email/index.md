---
title: Nodejs e email
date: "2020-07-22T00:00:00.000Z"
description: "Um amigo havia me passado um trabalho para fazer que era tecnicamente simples, pegar uma lista de email e criar um texto com esses email e enviar. Algo simples né? E até foi, até a hora de enviar o email de fato."
---


Sei que esse assunto é bem desenvolvido, mas gostaria de compartilhar uma experiencia que tive usando nodejs para envio de email. Segue o fluxo que no decorrer
 do texto vou explicar como consegui enviar uma lista de emails usando nodejs.
 
 ## Disclaimer
 
 Nesse texto não vou abordar um tutorial basico de como criar um serviço de envio de email, pois esses textos tem de monte na internet. Nesse texto vou discorrer
 sobre o problema que tinha que resolver enviando email e alguns impecilios que tive no meio do caminho.
 
 ## Problema
 
 Um amigo havia me passado um trabalho para fazer que era tecnicamente simples, pegar uma lista de email e criar um texto com esses email e enviar. Algo simples
 né? E até foi, até a hora de enviar o email de fato.
 
 ## Como comecei
 
 Comecei escrevendo a parte de parser dos dados da lista para montar o texto, percorrer a lista e enviar os emails.
 
 Apos criar o parser dos dados configurei o [envio de email usando nodemailer](https://stackabuse.com/how-to-send-emails-with-node-js/). Tudo bonitinho pronto 
 pronto para envio, comecei a usar os dados de produção apontando para meu email, junto com o email do meu amigo e aparentemente tudo ok.
 
 ## Problema
 
 Quando comecei a rodar os email com os dados de email certo começou a dor de cabeça. Alguns email não estavam sendo enviados, e aparentemente era só rodar de 
 novo para os emails serem enviados.
 
 Mesmo rodando novamente a lista de emails só eram enviados 5 a 10 email por vez. Então criei uma gambiarra com ajuda do meu amigo onde estavamos separando os 
 emails que não estavam sendo enviados e enviavamos novamente. Funcionou, mas como toda gambiarra isso tinha um preço e o preço a se pagar era em horas fazendo 
 aquele processo chato de pega os emails não enviados, separar para enviar novamente, rodar o script node e repetir todo o processo.
 
 ## Solução
 
 Após mais de duas horas fazendo aquele processo tivemos que reenviar mais emails. Ai surgiu uma ideia, "por que não usamos um slep (setimeout) para esperar um 
 pouco antes de enviar o proximo email. Fizemos o teste e como esperado, não funcionou de primeira. Pesquisamos um pouco e achamos isso que salvou o dia:
 
 
 [setTimeout not executing inside of map? or setTimeOut on map function?](https://stackoverflow.com/questions/46128650/settimeout-not-executing-inside-of-map-or-settimeout-on-map-function/61045303#61045303)
 
![Imagem da solução](https://raw.githubusercontent.com/enieber/blog/master/public/resposta-stackoverflow.png)

Como estavamos usando um map para percorrer a lista de emails e assim fazer o envio dos email tinha um problema que o servidor de email só aceitava uma quantidade
`x` de emails por segundo. A solução usando um setimeout crescente facilitou reenviar os restante de email.

## Conclusão

um `setimeout` dentro de um map é muito bom se usado de maneira crescente para criar uma fila falsa. Isso salvou pelo menos mais uma hora de trabalho e pode salvar 
algumas horas suas se você tiver um problema semelhante.
