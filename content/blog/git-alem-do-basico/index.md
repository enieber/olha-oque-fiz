---
title: Git alem do básico
date: "2018-04-18T00:00:00.000Z"
description: "Nesse guia que escrevi para me auxiliar como fazer o uso do git descrevo alguns comandos e o que eles faze."
---

# git

### iniciar o vercionamento
> git init 

## Config 

### configurando git
> git config --global user.name "Nome"

> git config --global user.email nome@dominio.com

### configurando servidor externo
adicionando novo servidor
> git remote add nome-de-atalho branche 


## adicionar alteração
> git add
 
## commitar alteração
> git commit -m "titulo de alteração"
 
## criar um branch e já apontar para ele
> git checkout -b nome-do-branch

## excluir branch 
> git branch -d nome-do-branch

## mesclar
> git merge nome-do-branch-que-vou-unificar

## ignorar arquivos

### criando
> .gitignore.

### editando

> pasta/
 arquivo.tipo
> git commit --amend
 
 
## Remover alterações
 
 alterações feitas mas não adicionadas 
 
 > git checkout -- caminho-do-arquivo 
 
## Git Rebase, o viajante do Tempo

**Cuidado para não matar seu avô**

Resnomear comitis, alterar a order
```
git rebase -i 

```

Apaga o comit, mas deixar alterações 
```
git reset HEAD-
```


```
git reset **nome do arquivo**
```

## Cada vez que é liberado para deploy
```
git tag
```

## Adicionando somente os arquivos que foram alterados

```
git add -p
```

