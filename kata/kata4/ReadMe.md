# 65 - Is Valid Number?

Check if a given stric has a numeric value writen.

Some examples:

```
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
```
**Note**: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.


## Analisis

El prof. Miguel Palomera respondio las siguientes preguntas via e-mail.

---

- ¿Hay algún tamaño máximo de los strings de entrada? Y si es así, ¿Cuál es?

- Pueden limitar a 255 caracteres.

- ¿Qué símbolos se utilizan para empezar la parte decimal de un numero? Es decir, si se utiliza el punto, coma, ambas u otro símbolo más.

- Para la parte decimail usen punto. Pero la coma también es valida por ejemplo 1,000.95 es valido. La coma debe estar en el lugar correcto. 10,0 este no es un número.

- Para la representación del número exponencial se ve en el ejemplo que “e” es válido. ¿Existe algún otro símbolo para esta representación, como por ejemplo ‘E’? en caso de ser afirmativo, ¿Cuáles son válidas para este problema? 

- Solo e en minúsculas. Después de la e no puede ir un número decial .ie. 45e87.98 no es valido pero e45 si, 

- Cuando el número tiene más de tres dígitos, ¿se utilizarán símbolos para separar los dígitos en grupos de tres?, en caso de ser afirmativo, ¿Qué símbolos se utilizarán en este problema?

- Es posible, pero no obligatorio, el simbolo sería la coma , .  1,000 y 1000 son correctos, i.e, la coma no es obligatoria

- Bajo el contexto del problema, ¿las operaciones validas cuentan como valores numéricos?, es decir, se en la información de entrada se encuentra “1+1”, ¿se regresara verdadero?

- No, las operaciones no cuentan como número. 1+1 no es un número. Ni tampoco cualquiera que tenga * + / Los únicos caracteres acepetados en un número son , . e 

- ¿Un numero valido decimal puede empezar con el punto?

- Si .5757 es valido

- Después del símbolo ‘e’ de exponente, ¿puede llevar signo para representar si es negativo o positivo?

- Si 45e-2 o 45e+56 es valido

- ¿Cualquier numero valido puede empezar “-” para saber si es negativo o “+” si es positivo?

- Si +45 o -45 son validos

- Profesor una pregunta para la Kata, ¿se pueden tener espacios en blanco antes y/o despues de el numero? Por ejemplo “    452.20    “

### ¿Como manejamos esta clase de casos?
    * La respuesta es si, se deben ignorar pueden tener un while(char == ' ') al principio y al final. Lo que no es valido son espacios intermedios
    * ¿Un numero decimal puede comenzar con un cero?    
    * 0.5757 Si y sin 0 también i.e, .5757
    * ¿Los numeros pueden ser octales o hexadecimales?
    * No solo decimales
    * pregunta seguida de ¿A que dominio pertenecen los numeros?
    * Solo decimales de menos infinito a + infinito.
    * ¿La construccion 00. es valida?
    * No, solo con un 0.1 es valida o .1 pero si 1.000 o .000

Hay que examinar y poder construir un *token* numerico que cumpla con las descripciones que definimos anteriormente. Se puede solucionar mediante un A.F.N para poder mostrar si la estructura de un token numérico aceptable, una vez que contamos con este automata la implementacion puede suceder de una manera mas natural.

## Imagen del Automata
![alt text](https://i.imgur.com/FS7NkYP.png)

Donde {n} es el conjunto que contiene todos los digitos del 0 al 9. En la imagen la mantisa fue la parte mas complicada de crear en este problema. Para pasar esto a codigo, se puede implementar un switch/case para estar comparando cada escenario.