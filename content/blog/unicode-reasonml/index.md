---
title: Unicode e acentuação em ReasonML
date: "2020-07-19T00:00:00.000Z"
description: "Quando estava escrevendo este blog me deparei com um problema, ao tentar renderizar o texto Formação, pois só tinha visto esse problema quando o tipo do arquivo não é UTF-8, porem não era esse o caso, pois o arquivo estáva com a formatação correta."
tags: ["reasonml", "utf-8", "unicode", "learn"] 
---

Quando estava escrevendo este blog me deparei com o seguinte problema, ao 
tentar renderizar o texto `Formação`, renderizou `FormaÃ§Ã£o`, para minha 
surpresa, pois só tinha visto esse problema quando o tipo do arquivo não é
UTF-8, porem não era esse o caso, pois o arquivo estáva com a formatação 
correta. Então passei para outras hipóteses:

- Não existe suporte para renderização UTF-8 e Unicode
- Existe uma forma diferente de renderizar textos com UTF-8 e Unicode.

## Pesquisa

Ao pesquisar achei uma [resposta interessante no stackeoverflow](https://stackoverflow.com/questions/56909028/how-to-display-emojis-with-reasonreact?answertab=active#tab-top)
que apontava para uma sintaxe diferente suportada pelo [bucklescript](https://bucklescript.github.io/),
ferramenta usada para compilar esse blog reasonml para nodejs.

## Solução

Para solucionar o problema, basta usar essa sintaxe um pouco diferente
para renderizar corretamente.

Maneira que estava usando:

```reason
  [@react.component]
  let make = () => <div>"💩 Formatação"->ReasonReact.string</div>

  let default = make
```

Renderiza sem erros:

```reason
  [@react.component]
  let make = () => <div>{j| 💩 Formatação |j}->ReasonReact.string</div>

  let default = make
```

## Explicação

Confesso que ainda não fui a fundo entender qual o motivo de não suportar
dentro da aspas dupla o código correto, pois o meu objetivo inicial erá lançar o blog.
 Ao final disso irei pesquisar e trazer atualizações sobre esse ponto.


