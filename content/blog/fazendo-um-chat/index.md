---
title: Fazendo um Chat com um passe de magica, ou quase
date: "2017-04-12T00:00:00.000Z"
description: "Como criar um chat xom um passe de magica usando docker e nodejs."
---

Para fazermos precisamos de uma receita:
- primeiro vamos precisar de uma imagem docker para rodar o nodejs
- depois vamos precisar de instalar os pacotes socket.io e express para fazermos um servidor de chat
- depois fazemos os codigos e tcharaaaaa

## pronto!!

SQN nem tudo é um passe de magica, para isso me baseei em um video sobre Nodejs e socket.io.

Primeiro eu criei uma imagem baseada no node:alpine por ser uma das imagens mais portaveis de docker:

```Dockerfile
FROM node:7.7-alpine

RUN mkdir src/
WORKDIR src/

COPY . src/
COPY package.json

RUN npm install

RUN npm install

EXPOSE 3000

CMD [“npm”, “start”]
```

Depois disso criei um arquivo chamado package.json e colocar as dependencias do projeto:

```json
{
  "name": "chat",
  "version": "1.0.0",
  "description": "",
  "main": "index.js",
  "scripts": {
    "start": "node server.js",
  },
  "keywords": [],
  "author": "Enieber Cunha <eniebercunha@gmail.com>",
  "license": "ISC",
  "dependencies": {
    "express": "^4.15.2",
    "socket.io": "^1.7.3"
  }
}
```

depois você cria um arquivo chamado serve.js que vai fazer a comunicação entre o cliente e o servidor atravez do socket.io:

```js
const express = require('express')
const socket = require('socket.io')

const app = express()
const io = socket.listen(app.listen(3000))
console.log('App listening on 3000')

io.sockets.on('connection', (sock) => {
  console.log('connected to socket')
  sock.on('client emit', (msg) => {
    io.emit('server emit', msg)
  })
})

app.use(express.static(__dirname + "/public"))
```

Apos criado o servidor, precisaremos de um cliente para se comunicar com o servidor e enviar mensagem que vai ser recebida pelo servidor e enviada para todos que estiver conectados ao mesmo soket, chamamos o arquivo de index.html pois vai ser renderizado no browser:

```html
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8">

    <title>Chat </title>

  </head>
  <body>
    <h2>Real time application</h2>

    <ul id="messages"></ul>

    <form id="form">
      <input id="text" type="text">
      <button id="sendButton"> Send </button>
    </form>

    <script src="/socket.io/socket.io.js"></script>
    <script>
      var socket = io()
      document.getElementById('form').addEventListener('submit', function(e){
        e.preventDefault()
      })
      document.getElementById('sendButton').onclick = function () {
        var msg = document.getElementById('text')
        socket.emit('client emit', msg.value)
        msg.value = ''
      }
      socket.on('server emit', function(msg) {
        var messages = document.getElementById('messages')
        var newLi = document.createElement('li')
        newLi.innerHTML = msg
        messages.appendChild(newLi)
      })
    </script>

  </body>
</html>
```

## Criando Imagem docker

- primeiro você faz o builld do container:

    `docker build -t chat-node. run`

- depois você roda o container com o comando para ver se ele esta ok:

    `docker run -p 3000:3000 -d chat-node`

## Final

agora vamos adicionar um arquivo docker-compose.yml

```yml
version: '2'
services:
 app:
   image: node-chat
   ports:
     — “3000:3000”
```

assim conseguiremos adicionar um banco de dados muito mais faci.

pra finalizar, só rodar o comando:

`docker-compose up`

e assim o container sera rodado com o nosso chat na port http://localhost:3000

