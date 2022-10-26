---
title: "Nombres complexes"
tags: Maths
---

## Formes des nombres complexes
- **Forme algébrique :** $z = a+bi$
- **Forme trigonométrique :** $z= |z| \times (\cos{\theta}+i\sin{\theta})$ 
- **Forme exponentielle :** $z = |z|\times e^{i\theta}$

Pour passer de la forme algébrique à une autre, il faut calculer le module et l'argument.

## Propriétés du module
**Définition du module :** $|z| =\sqrt{a^2+b^2}$ 
- $|z| = 0 \iff z=0$
- $|z|=|\overline{z}|= |-\overline{z}|=|-z|$ 
- $z\cdot \overline{z} = |z|^2$
- $|z\cdot \overline{z}| = |z|\cdot|\overline{z}|$ et donc $\left|\frac{z}{\overline{z}} \right|= \frac{|z|}{|\overline{z}|}$  
- $\forall n \in \mathbb{N}, |z^n|=|z|^{n}$  
- **Inégalité triangulaire :** $|z+z'| \leq |z|+|z'|$    
## Propriétés de l'argument
**Définition de l'argument :** 

$$
\begin{equation*}
  \theta = arg(z)(mod(2\pi)) \iff
     \begin{cases}
        \cos{\theta}=\frac{Re(z)}{|z|} \\
        \sin{\theta}=\frac{Im(z)}{|z|}
     \end{cases}
\end{equation*}
$$

$$
\theta = arg(z)(mod(2\pi)) \iff \left \{\begin{array}{rcl}\cos{\theta}=\frac{Re(z)}{|z|} \\\sin{\theta}=\frac{Im(z)}{|z|}\end{array}\right.
$$

- $arg(\overline{z}) =-arg(z) (mod~2\pi)$
- $arg(-\overline{z}) =\pi-arg(z) (mod~2\pi)$ 
- $arg(z) =\pi+arg(z) (mod~2\pi)$
- $arg(z\cdot z')=arg(z)+arg(z')(mod~2\pi)$ et donc $arg\left(\frac{z}{z'} \right)= arg(z)-arg(z')(mod~2\pi)$  
- $\forall n \in \mathbb{N}, arg(z^{n})=n\cdot arg(z)(mod~2\pi)$

## Trigonométrie
![Cercle trigonométrique](images/cercle_trigo.png)


### Formules de trigonométrie
**Additions et soustractions :** 
- $\sin(a+b) = \sin{a}\cos{b} + \sin{b}\cos{a}$ et $\sin(a-b)=\sin{a}\cos{b}-\sin{b}\cos{a}$
- $\cos(a+b)=\cos{a}\cos{b}-\sin{a}\sin{b}$ et $\cos(a-b)=\cos{a}\cos{b}+\sin{a}\sin{b}$
- $\cos(a)\cos(b)=\frac{1}{2}(\cos(a+b)+\cos(a-b))$
- $\sin(a)\sin(b)=\frac{1}{2}(\cos(a-b)-\cos(a+b))$
- $\sin(a)\cos(b)=\frac{1}{2}(\sin(a+b)+\sin(a-b))$


**Autres formules**
$$
\cos^{2}a+ \sin^{2}a= 1
$$
D'où les formules suivantes :
- $\cos(2a)=\cos^2a-\sin^{2}a=2\cos^2a-1=1-2\sin^2a$
- $\sin(2a)=2\sin{a}\cos{a}$

**Tangente** : $\tan\theta =\frac{\sin\theta}{\cos\theta}$ 
- $\tan(a+b)=\frac{\tan{a}+\tan{b}}{1-\tan{a}\tan{b}}$
- $\tan(a-b)=\frac{\tan{a}-\tan{b}}{1+\tan{a}\tan{b}}$

**Formule d'Euler, application aux nombres complexes**
$$
\cos\theta =\frac{e^{i\theta}+e^{-i\theta}}{2} \iff 2\cos\theta=e^{i\theta}+e^{-i\theta}$$
$$
\sin\theta=\frac{e^{i\theta}-e^{-i\theta}}{2i} \iff 2i\sin\theta=e^{i\theta}-e^{-i\theta}
$$

## Méthodes
### Linéarisation
**Objectif :** Transformer des $\sin^{n}x$ et $\cos^{n}x$  en somme de $\sin(nx)$ et $\cos(nx)$
*Cela peut permettre de trouver des primitives par exemple*

1. Réecriture des  $\sin^{n}x$ et $\cos^{n}x$ en utilisant la **formule d'Euler**
$$
\cos^{n}\theta=\left(\frac{e^{i\theta}+e^{-i\theta}}{2}\right)^{n}
$$
2. Développement avec le binôme de Newton :
$$
\cos^{n}\theta=\frac{1}{2^{n}}\left(\sum_{k=0}^{n}\binom{n}{k}e^{i\theta(n-k)}\cdot e^{i\theta k}  \right)
$$
3. Regroupement des exponentielles de même puissance. *Par exemple : $cos^{3}x=\frac{1}{8}(e^{3ix}+3e^{ix}+3e^{-ix}+e^{-3ix})\iff \frac{1}{8}(e^{3ix}+e^{-3ix}+3(e^{ix}+e^{-ix}))$ 
4. Réutilisation des formules d'Euler $2\cos\theta=e^{i\theta}+e^{-i\theta}$ et $2i\sin\theta=e^{i\theta}-e^{-i\theta}$
   *Par exemple :* $cos^{3}x=\frac{1}{8}(2\cos(3x)+3\cdot2\cos(x))$ 
5. Simplification par 2

> [!danger] Attention pour la linéarisation des sinus
> 
> Ne pas oublier les **i**, aussi bien dans les $\frac{1}{(2i)^n}$ que dans les formules d'Euler : $2i\sin\theta=e^{i\theta}-e^{-i\theta}$

On peut aussi utiliser les formules de trigonométrie usuelles pour linéariser.

> [!info] Info sur la linéarisation
> 
> - Si la fonction à linéariser est paire, on obtiendra au final que des cosinus (car cos est paire)  
> - Si la fonction à linéariser est impaire, on aura au final que des sinus (car sin est impaire)


### Racines d'un nombre complexe
L'équation $z^{n}=a$ possède $n$ solutions que l'on appelle les racines $n$-ièmes de $a$.
Par exemple, pour $z^{2}=|z|\cdot e^{i\theta}$, ses racines sont $z_{1}=|z|^{1/2}e^{\frac{i\theta}{2}}$ et $z_{2}=|z|^{1/2}e^{i(\frac{\theta}{2}+\pi)}$  

Pour trouver les racines $n$-ièmes, il faut trouver la racine évidente ($z_{1}=|z|^{1/n}e^{\frac{i\theta}{n}}$) et les racines $n$-ièmes de l'unité, c'est-à-dire, les solutions de : $w^{n}=1$ 

---

[_index](_index.md)
[Accueil](_index.md)