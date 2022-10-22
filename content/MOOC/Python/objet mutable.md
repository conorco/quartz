---
tags : code
date : 22/02/22
---

# Objet mutable
### Les chaînes sont des objets immuables

Voici un exemple d'un fragment de code qui illustre le caractère immuable des chaînes de caractères. 

Le scénario est très simple, on crée deux variables `s1` et `s2` vers le même objet `'abc'`, puis on fait une opération `+=` sur la variable `s1`.

Comme l'objet est une chaîne, il est donc immuable, on ne **peut pas modifier l'objet** directement ; pour obtenir l'effet recherché (à savoir que `s1` s'allonge de `'def'`), Python **crée un deuxième objet**, comme on le voit bien sous pythontutor :
![[Pasted image 20220222102737.png]]
```python
# à se stade avec des chaines on observe
s1 = 'abc'
s2 = s1
s1 += 'def'
print(s1) # 'abcdef'
print(s2) # 'abc'
```

### Les listes sont des objets mutables

Voici ce qu'on obtient par contraste pour le même scénario mais qui cette fois utilise des listes, qui sont des objets mutables :
![[Pasted image 20220222102755.png]]

```python
# alors qu'avec les listes on observe
liste1 = ['a', 'b', 'c']
liste2 = liste1
# on modifie l'objet
liste1 += ['d', 'e', 'f']
print(liste1) # ['a', 'b', 'c','d', 'e', 'f']
print(liste2) # ['a', 'b', 'c','d', 'e', 'f']
```

### Conclusion

Ce comportement n'est pas propre à l'usage de l'opérateur `+=`, les objets mutables et immuables ont par essence un comportement différent, il est très important d'avoir ceci présent à l'esprit.
