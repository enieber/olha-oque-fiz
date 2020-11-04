---
title: Criando api em OCaml usando Opium
date: "2020-11-04T00:00:00.000Z"
description: "Vamos criar uma api basica de ocaml usando opium"
---

Estou estudando ReasonML a algum tempo e para me aprofundar na liguagem resolvir escrever uma api, graças a uma live feita pelo EduardoRFS na Twitch 
explicando passo a passo como criar uma api usando Opium, resolvi o livecode e criar uma api e no caminho escrever um post sobre o processo.

## Para começar

Para começar vamos detalhar as ferramentas usadas para criar a api:

### reasonml

Aqui usaremos [ReasonML](https://reasonml.github.io/) para escrever todo o codido. Como Reasonml é uma linguagem compativel com Ocaml poderemos usar alguns exemplos de Ocaml transformando
em ReasonMl com [Try do Reasonml](https://reasonml.github.io/en/try)

### opium

O [Opium](https://github.com/rgrinberg/opium) é uma lib like sinatra, ou seja, baseada no [framework sinatra](http://sinatrarb.com/), um a api simples
com uma estrutura não definida.

### esy

O [esy](https://esy.sh/en/) é uma ferramenta semelhante ao yarn no mundo nodejs, porem o esy foi criado para auxiliar instalar e rodar scripts para 
reason/ocaml.

### dune

O [dune](https://dune.build/) é usado para compilar executaveis, bibliotecas, rodar teste e muito mais para reason/ocaml que se assemelha ao webpack do nodejs
