# 🖨️ ft_printf

Une implémentation personnalisée de la fonction `printf` de la bibliothèque standard C, développée dans le cadre du cursus de l'École 42. Cette fonction reproduit le comportement de `printf` avec les spécificateurs de format les plus couramment utilisés.

## 📋 Table des matières

- [À propos](#à-propos)
- [Fonctionnalités](#fonctionnalités)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Structure du projet](#structure-du-projet)
- [Spécificateurs supportés](#spécificateurs-supportés)
- [Compilation](#compilation)
- [Tests](#tests)
- [Performance](#performance)
- [Auteur](#auteur)

## 🔍 À propos

**ft_printf** est une recreation de la fonction `printf` de la libc qui permet d'afficher du texte formaté sur la sortie standard. Cette implémentation gère les conversions les plus importantes et constitue un excellent exercice pour comprendre les fonctions variadiques et la manipulation de formats.

### Caractéristiques principales :
- **Fonctions variadiques** : Gestion d'un nombre variable d'arguments
- **Spécificateurs de format** : Support des conversions essentielles
- **Gestion des types** : Entiers, chaînes, caractères, pointeurs, hexadécimal
- **Valeur de retour** : Nombre de caractères imprimés
- **Robustesse** : Gestion des cas particuliers et des erreurs

## ✨ Fonctionnalités

- 🔤 **Caractères** : `%c` - Affichage de caractères
- 📝 **Chaînes** : `%s` - Affichage de chaînes de caractères
- 🔢 **Entiers** : `%d`, `%i` - Nombres entiers signés
- 📊 **Non signés** : `%u` - Nombres entiers non signés
- 🔍 **Hexadécimal** : `%x`, `%X` - Conversion hexadécimale (minuscules/majuscules)
- 📍 **Pointeurs** : `%p` - Affichage d'adresses mémoire
- ⚡ **Pourcentage** : `%%` - Caractère littéral '%'
- 💾 **Gestion mémoire** : Aucune fuite mémoire
- 📏 **Valeur de retour** : Compte précis des caractères affichés

## 🚀 Installation

### Prérequis

- GCC ou Clang
- Make
- Système Unix/Linux

### Compilation

```bash
# Cloner le projet
git clone https://github.com/votre-username/ft_printf.git
cd ft_printf

# Compiler la bibliothèque
make

# Nettoyer les fichiers objets
make clean

# Nettoyer complètement
make fclean

# Recompiler
make re
```

## 💻 Utilisation

### Intégration dans un projet

```c
#include "ft_printf.h"

int main(void)
{
    int len;
    
    len = ft_printf("Hello, %s! You have %d new messages.\n", "Alice", 5);
    ft_printf("Printed %d characters\n", len);
    
    return (0);
}
```

### Compilation avec votre projet

```bash
# Compiler votre projet avec ft_printf
gcc -Wall -Wextra -Werror your_file.c -L. -lftprintf -o your_program

# Ou inclure directement
gcc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

## 📁 Structure du projet

```
ft_printf/
├── Makefile                   # Script de compilation
├── ft_printf.h               # Header principal
└── src/
    ├── ft_printf.c           # Fonction principale
    ├── ft_format.c           # Gestion des spécificateurs
    ├── ft_isformat.c         # Validation des formats
    ├── ft_putchar.c          # Affichage de caractères
    ├── ft_putstr.c           # Affichage de chaînes
    ├── ft_putnbr.c           # Affichage d'entiers signés
    ├── ft_printu.c           # Affichage d'entiers non signés
    ├── ft_hexa.c             # Conversion hexadécimale
    └── ft_ptr.c              # Affichage de pointeurs
```

## 🔧 Spécificateurs supportés

### Vue d'ensemble

| Spécificateur | Type | Description | Fonction |
|---------------|------|-------------|----------|
| `%c` | `int` | Caractère | [`ft_putchar`](ft_putchar.c) |
| `%s` | `char *` | Chaîne de caractères | [`ft_putstr`](ft_putstr.c) |
| `%p` | `void *` | Pointeur (adresse) | [`ft_ptr`](ft_ptr.c) |
| `%d` | `int` | Entier décimal signé | [`ft_putnbr`](ft_putnbr.c) |
| `%i` | `int` | Entier décimal signé | [`ft_putnbr`](ft_putnbr.c) |
| `%u` | `unsigned int` | Entier décimal non signé | [`ft_printu`](ft_printu.c) |
| `%x` | `unsigned int` | Hexadécimal minuscules | [`ft_hexa`](ft_hexa.c) |
| `%X` | `unsigned int` | Hexadécimal majuscules | [`ft_hexa`](ft_hexa.c) |
| `%%` | - | Caractère littéral '%' | [`ft_putchar`](ft_putchar.c) |

### Détails des conversions

#### Caractères (`%c`)

```c
ft_printf("Caractère: %c\n", 'A');
// Sortie: Caractère: A
```

#### Chaînes (`%s`)

```c
ft_printf("Message: %s\n", "Hello World");
// Sortie: Message: Hello World

ft_printf("Null: %s\n", NULL);
// Sortie: Null: (null)
```

#### Pointeurs (`%p`)

```c
int var = 42;
ft_printf("Adresse: %p\n", &var);
// Sortie: Adresse: 0x7fff5fbff6ac

ft_printf("Pointeur null: %p\n", NULL);
// Sortie: Pointeur null: (nil)
```

#### Entiers signés (`%d`, `%i`)

```c
ft_printf("Positif: %d\n", 42);
// Sortie: Positif: 42

ft_printf("Négatif: %d\n", -42);
// Sortie: Négatif: -42

ft_printf("Zéro: %i\n", 0);
// Sortie: Zéro: 0
```

#### Entiers non signés (`%u`)

```c
ft_printf("Non signé: %u\n", 42U);
// Sortie: Non signé: 42

ft_printf("Maximum: %u\n", 4294967295U);
// Sortie: Maximum: 4294967295
```

#### Hexadécimal (`%x`, `%X`)

```c
ft_printf("Hexa min: %x\n", 255);
// Sortie: Hexa min: ff

ft_printf("Hexa maj: %X\n", 255);
// Sortie: Hexa maj: FF

ft_printf("Zéro hexa: %x\n", 0);
// Sortie: Zéro hexa: 0
```

## 🛠️ Implémentation

### Fonction principale ([`ft_printf.c`](ft_printf.c))

```c
int ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    int     len;

    va_start(args, format);
    i = 0;
    len = 0;
    if (!format)
        return (-1);
    while (format[i])
    {
        if (format[i] == '%' && ft_isformat(format[i + 1]) == 1)
        {
            len += ft_format(args, format[i + 1]);
            i++;
        }
        else
            len += ft_putchar(format[i]);
        i++;
        if (len == -1)
            return (len);
    }
    va_end(args);
    return (len);
}
```

### Gestionnaire de formats ([`ft_format.c`](ft_format.c))

```c
int ft_format(va_list args, char c)
{
    int                 len;
    unsigned long int   ptr;

    len = 0;
    if (c == 'c')
        len += ft_putchar(va_arg(args, int));
    else if (c == 's')
        len += ft_putstr(va_arg(args, char *));
    else if (c == 'p')
    {
        ptr = va_arg(args, unsigned long int);
        if (!ptr)
            return (len += write(1, "(nil)", 5));
        len += write(1, "0x", 2);
        len += ft_ptr(ptr);
    }
    else if (c == 'd' || c == 'i')
        len += ft_putnbr(va_arg(args, int));
    else if (c == 'x' || c == 'X')
        len += ft_hexa(va_arg(args, unsigned int), c);
    else if (c == 'u')
        len += ft_printu(va_arg(args, unsigned int));
    else if (c == '%')
        len += ft_putchar(c);
    return (len);
}
```

### Validation des formats ([`ft_isformat.c`](ft_isformat.c))

```c
int ft_isformat(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
        || c == 'u' || c == 'x' || c == 'X' || c == '%')
        return (1);
    return (0);
}
```

## 🧪 Tests

### Tests basiques

```c
#include "ft_printf.h"

int main(void)
{
    int ft_len, std_len;
    
    // Test caractère
    ft_len = ft_printf("ft_printf: %c\n", 'A');
    std_len = printf("printf:    %c\n", 'A');
    printf("Longueurs: ft=%d, std=%d\n\n", ft_len, std_len);
    
    // Test chaîne
    ft_len = ft_printf("ft_printf: %s\n", "Hello");
    std_len = printf("printf:    %s\n", "Hello");
    printf("Longueurs: ft=%d, std=%d\n\n", ft_len, std_len);
    
    // Test entier
    ft_len = ft_printf("ft_printf: %d\n", -42);
    std_len = printf("printf:    %d\n", -42);
    printf("Longueurs: ft=%d, std=%d\n\n", ft_len, std_len);
    
    // Test hexadécimal
    ft_len = ft_printf("ft_printf: %x %X\n", 255, 255);
    std_len = printf("printf:    %x %X\n", 255, 255);
    printf("Longueurs: ft=%d, std=%d\n\n", ft_len, std_len);
    
    return (0);
}
```

### Testeurs recommandés

```bash
# ft_printf tester
git clone https://github.com/Tripouille/printfTester.git
make -C printfTester

# PFT - Printf Unit Test
git clone https://github.com/cclaude42/PFT_2019.git
make -C PFT_2019
```

### Tests de robustesse

```c
// Tests cas limites
ft_printf("%s\n", NULL);           // (null)
ft_printf("%p\n", NULL);           // (nil)
ft_printf("%d\n", INT_MIN);        // -2147483648
ft_printf("%d\n", INT_MAX);        // 2147483647
ft_printf("%u\n", UINT_MAX);       // 4294967295
ft_printf("%%\n");                 // %
ft_printf("%\n");                  // Comportement indéfini
```

## ⚡ Performance

### Optimisations implémentées

- **Appels système minimisés** : Utilisation efficace de `write()`
- **Récursivité optimisée** : Fonctions [`ft_putnbr`](ft_putnbr.c), [`ft_hexa`](ft_hexa.c), [`ft_ptr`](ft_ptr.c)
- **Pas d'allocation dynamique** : Utilisation de variables automatiques
- **Gestion d'erreurs rapide** : Retour immédiat en cas d'erreur

### Complexité

| Fonction | Complexité | Performance |
|----------|------------|-------------|
| `ft_printf` | O(n) | Linéaire avec la taille du format |
| `ft_putnbr` | O(log n) | Logarithmique avec la valeur |
| `ft_hexa` | O(log n) | Logarithmique en base 16 |
| `ft_putstr` | O(n) | Linéaire avec la longueur |

## 🔍 Exemples avancés

### Formatage multiple

```c
int age = 25;
char *name = "Alice";
void *ptr = &age;

ft_printf("Nom: %s, Age: %d ans\n", name, age);
ft_printf("Adresse de age: %p\n", ptr);
ft_printf("Age en hexa: %x (maj: %X)\n", age, age);
ft_printf("Pourcentage: 100%%\n");
```

### Gestion des cas spéciaux

```c
// Chaînes NULL
ft_printf("String: '%s'\n", NULL);
// Sortie: String: '(null)'

// Pointeurs NULL
ft_printf("Pointer: %p\n", NULL);
// Sortie: Pointer: (nil)

// Nombres limites
ft_printf("MIN: %d, MAX: %d\n", INT_MIN, INT_MAX);
// Sortie: MIN: -2147483648, MAX: 2147483647
```

### Comparaison avec printf

```c
int ft_ret, std_ret;

ft_ret = ft_printf("ft_printf: %d %s %p\n", 42, "test", &ft_ret);
std_ret = printf("printf:    %d %s %p\n", 42, "test", &std_ret);

ft_printf("Retours: ft=%d, std=%d\n", ft_ret, std_ret);
```

## 🧮 Algorithmes utilisés

### Conversion d'entiers ([`ft_putnbr.c`](ft_putnbr.c))

```c
int ft_putnbr(int nb)
{
    int             len;
    long long int   n;

    len = 0;
    n = nb;
    if (n < 0)
    {
        len += ft_putchar('-');
        n *= -1;
    }
    if (n >= 0 && n <= 9)
        len += ft_putchar(n + '0');
    else
    {
        len += ft_putnbr(n / 10);
        len += ft_putnbr(n % 10);
    }
    return (len);
}
```

### Conversion hexadécimale ([`ft_hexa.c`](ft_hexa.c))

```c
int ft_hexa(unsigned int nb, char c)
{
    int len;

    len = 0;
    if (nb >= 16)
        len += ft_hexa(nb / 16, c);
    if (nb % 16 <= 9)
        len += ft_putchar((nb % 16) + '0');
    else
    {
        if (c == 'X')
            len += ft_putchar((nb % 16) + 55);  // A-F
        else
            len += ft_putchar((nb % 16) + 87);  // a-f
    }
    return (len);
}
```

### Gestion des pointeurs ([`ft_ptr.c`](ft_ptr.c))

```c
int ft_ptr(unsigned long nb)
{
    int len;

    len = 0;
    if (nb >= 16)
        len += ft_ptr(nb / 16);
    if (nb % 16 <= 9)
        len += ft_putchar((nb % 16) + '0');
    else
        len += ft_putchar((nb % 16) + 87);  // a-f seulement
    return (len);
}
```

## 🏫 Projet 42

Ce projet permet d'apprendre :

- **Fonctions variadiques** : `va_list`, `va_start`, `va_arg`, `va_end`
- **Manipulation de formats** : Parsing et validation
- **Conversions numériques** : Bases décimale et hexadécimale
- **Gestion mémoire** : Pas d'allocation, gestion des fuites
- **Debugging avancé** : Comparaison avec `printf` standard
- **Architecture modulaire** : Séparation des responsabilités

### Compétences développées

- 🔧 **Programmation système** : Fonctions variadiques
- 🧮 **Algorithmes** : Conversions numériques récursives
- 📊 **Gestion des types** : Casting et manipulation
- 🐛 **Debugging** : Tests comparatifs et validation
- 📚 **Documentation** : Comprendre les spécifications

## 📚 Ressources utiles

- [Fonctions variadiques](https://en.cppreference.com/w/c/variadic)
- [Documentation printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Testeur printf](https://github.com/Tripouille/printfTester)
- [Conversion de bases](https://en.wikipedia.org/wiki/Radix)

## 🐛 Debugging

### Outils recommandés

```bash
# Vérification des fuites mémoire
valgrind --leak-check=full ./test_printf

# Comparaison avec printf standard
diff <(./ft_printf_test) <(./printf_test)

# Tests de performance
time ./ft_printf_test
```

### Erreurs communes

- **Segmentation fault** : Vérifier les pointeurs NULL
- **Mauvaise valeur de retour** : Compter tous les caractères
- **Conversion incorrecte** : Vérifier les algorithmes de base
- **Gestion de %%** : Ne pas oublier le caractère littéral

## 👨‍💻 Auteur

**rwassim** - Étudiant à l'École 42

- GitHub: [@rwassim](https://github.com/mossfreestyle)
- Email: rwassim@student.42.fr

## 📄 Licence

Ce projet est développé dans le cadre du cursus de l'École 42. Code disponible pour l'apprentissage et la référence.

---

⭐ **Printf maîtrisé, fonctions variadiques comprises !**

*Développé avec ❤️ à l'École 42*
