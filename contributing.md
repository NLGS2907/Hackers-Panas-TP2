Este archivo contiene una especie de tutorial sobre cómo los contribuidores de este repositorio deberían (valga la redundancia) "contribuir" con sus *commits* y demás.
Al ser un repositorio más o menos temporal para el desarrollo de un TP, no se espera un acatamiento muy estricto, pero la forma general en caso de duda se detalla a continuación.

## **Índice**

* [Usando GitKraken](#usando-gitkraken)

<hr/>

La manera en que **Hackers-Panas-TP2** opera es mediante los llamados *pull requests*, para los cuales el codigo fuente se desarrolla de la siguiente manera:

## Usando **GitKraken**

1. En caso de usar un software que gestione un clon 'local' del repositorio (como **GitHub Desktop** o **GitKraken**), crear una rama en el repositorio local
para el uso personal del colaborador. Preferiblemente del formato ***[NombreInicialApellido]***. Así, "*Franco Lighterman*" sería **"FrancoL"**.

  <img alt="*GitKraken: Creando un nueva rama en el repositorio*" src="readme/imgReadme/creating_new_branch.gif" width="315" height="375">

2. Todos los *commits* y *pushs* al repositorio remoto de ese colaborador deberían ser hechas a su respectiva rama, la cual no está protegida por ninguna regla,
por lo que se confía en no haber modificaciones hechas sin permiso debido por otro usuario que no sea el colaborador asignado a esa rama.

  <img alt="*GitKraken: Aplicando los cambios al clon de repositorio local (commits)*" src="readme/imgReadme/commiting_new_changes.gif" width="585" height="479">
  <img alt="*GitKraken: Subiendo los cambios del clon local al repositorio remoto*" src="readme/imgReadme/pushing_to_origin.gif" width="585" height="479">

3. Cuando ese colaborador quiere contribuir con un cambio o retoque al código fuente de la rama principal *main*, o contribuir al proyecto con un algoritmo que hizo,
debe abrir un *pull request*, el cual dos (2) otros colaboradores más deben aprobar. De ser así, dicho cambio se une a la rama *main*.

  <img alt="*GitKraken: Craendo Pull Requests*" src="readme/imgReadme/creating_a_request.gif" width="585" height="479">
  <img alt="*GitKraken: Revisando Pull Requests*" src="readme/imgReadme/reviewing_a_request.gif" width="780" height="464">

(**NOTA:** Salvo que se pida pasar archivos específicos, hay riesgo de que se trate de pullear una rama entera a la principal y sobreescribirla, por lo que para reducir
dicho riesgo, cada vez que se apruebe un cambio en el principal, cada rama debería pullear esos cambios para que el mismo se refleje en todas las ramas).



*Todas las normas comunes explicadas arriba están sujetas a posterior revisión y/o modificación por parte de los demás colaboradores.*
