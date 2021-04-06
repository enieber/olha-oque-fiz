---
title: React Native e tipagem
date: "2018-12-31T00:00:00.000Z"
description: "Recentemente comecei a testar algumas alternativas para escrever aplicativos de fácil manutenção e documentação com menor número de erros possíveis com react-native usando tipagem."
---

Recentemente comecei a testar algumas alternativas para escrever aplicativos de fácil manutenção e documentação com menor número de erros possíveis com react-native usando tipagem.

A primeira alternativa foi usar a lib prop-types que pode ser facilmente integrada em um aplicativo react, mas apesar de ser uma boa alternativa minha busca era por algo que fosse compilado, pois o compilador poderia me mostrar erros simples e até fazer otimizações que eu não conseguiria pensar.

Outras duas alternativas que tinha em mente era usar Typescript, pois é um framework bastante popular com uma comunidade bem ativa e ReasonML que é uma linguagem que venho estudando um pouco e até escrevi um post explicando o motivo que comecei a estudar.

Para entender as vantagens que eu conseguiria obter de cada tecnologia resolvi escrever um aplicativo que gerasse alguns tokens randomicamente.

Primeiro comecei com ReasonML para react-native seguindo um post bem interessante sobre como começar um app usando a linguagem comecei a escrever o aplicativo.

Como já tinha alguma familiaridade com a linguagem não foi muito difícil começar, o problema foi entender como importar um modulo em ReasonML/OCaml ou um modulo js, tive alguns problemas e para agilizar resolvi criar a função.

Então comecei testando o Módulo de Random do ReasonML, mas consegui gerar apenas números aleatórios. Como o intuito era gerar uma sequência de strings aleatórios resolvi criar com js puro. Com isso consegui criar o que eu queria de maneira fácil.

Após ter feito o aplicativo em ReasonML resovi criar o mesmo aplicativo em Typescript para ver quais vantagens ele poderia me dar comparando com ReasonML. Para isso tentei seguir diversos posts mas nenhum foi tão decisivo quanto a própria documentação do react-native. Tive alguns outro probleminhas que estão ligados a como escrever o componente, mas foram coisas relacionadas a sintaxe que não foram tão complicadas de se resolver.

No final acabei escrevendo um aplicativo com TypeScript sem o problema de Hot-Reload que tive com ReasonML. Outra vantagem do TypeScript é que para escrever um aplicativo do zero é muito mais fácil por sua sintaxe ser semelhante, muito mais semelhante ao js o que não me obriga a mudar a forma de escrever um componente como é o caso dos apps feitos com ReasonML.

Essa minha escolha não significa que vou parar de estudar ReasonML para me limitar a TypeScript, apenas que para criar aplicativos simples de maneira rápida vou usar as vantagens que o TypeScript me oferece.

## Conclusão

Minha conclusão sobre as linguagens que comparei para criar aplicativos em react-native.

### TypeScript

**pros:**

- fácil de começar
- fácil de integrar códigos js
- sintaxe semelhante a js puro.
- fácil fazer integração com react-native
- muito conteúdo produzido pela comunidade

**contras:**

- dificuldade de entender como funciona a tipagem
- sem garantia de que o código que foi compilado realmente vai funcionar
- tipagem apenas para props e states

### ReasonML

**pros:**

- tipagem bem robusta
- tipagem de styles (isso é muito top)
- rápida compilação
- geração de um código que estará funcionando em 95% das vezes.

**contras:**

- não tem suporte ao hot-reload do react-native, de maneira simples.
- dificuldade em entender a sintaxe da linguagem.
- pouco material produzido pela comunidade.

## Disclaimer

Todos esses pontos são apenas minha visão sobre as tecnologias, não quer dizer que exista outra forma de fazer com outros resultados. Caso fique curioso como ficou os aplicativos pode conferir no meu github o projeto da [PoC com TypeScript](https://github.com/enieber/poc-rn-typscript) e a [PoC com ReasonML.](https://github.com/enieber/poc-rn-reason)
