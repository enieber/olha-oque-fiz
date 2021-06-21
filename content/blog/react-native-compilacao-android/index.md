---
title: Agilizando a compilação para Android usando react-native com alias
date: "2018-09-21T00:00:00.000Z"
description: "Quando comecei a desenvolver em React Native tive muitos problemas com o cache do android, tanto o cache das libs quanto o cache gerado do próprio projeto."
tags: ["android", "react-native", "compilação", "tools"]
---

Quando comecei a desenvolver em React Native tive muitos problemas com o cache do android, tanto o cache das libs quanto o cache gerado do próprio projeto. Para fazer uma compilação simples tinha que ficar removendo pastas e verificando respostas a erros de cache no stackoverflow.

Com o tempo, peguei experiência nesses erros e para evita-los criei algumas libs que me auxiliam no dia a dia e para facilitar outros projeto [criei um repositório no GitHub.](https://github.com/enieber/alias/blob/master/rn-android.md)

React Native Android Alias

Explicando um pouco mais os alias, os que mais utilizo são:

- rn-clear: Neste alias eu removo toda a pasta de build do android, assim tenho um projeto sem cache.
- rn-start: Aqui uso para dar o start do projeto em modo dev, ou seja, para compilar o projeto para algum device.
- ad-clear: Serve para fazer o clear do projeto, semelhante ao clear do Android Studio, removendo até o cache das libs nativas.
- rn-server: Neste alias uso para subir o servidor nodejs que será responsável por enviar o código js para o app em desenvolvimento.

## Conclusões

Apesar do projeto parecer algo besta, ja economizei horas e horas com esses alias, pois com eles consigo fazer a compilação para um projeto em modo de desenvolvimento:

`rn-clear && rn-start`

remover o cache de libs caso eu tenha adicionado uma nova versão de uma lib nativa:

`ad-clean && rn-clear && rn-start`

ou ainda compilar para produção sem muitos problemas, basta o projeto estar configurado corretamente com a assinatura e versão ok que consigo rodar o seguinte comando e ser feliz:

`ad-clean && rn-clear && rn-release`

Caso tenha gostado e quiser contribuir com o projeto basta enviar um Pull Request ou abrir uma Issue.

https://github.com/enieber/alias
