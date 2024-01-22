# Ndiaye Lab1

# I. Introduction :
L'objectif de ce rapport est de présenter le travail réalisé au cours des travaux pratiques de l'UE Conception Conjointe, axés sur l'approfondissement et la mise en pratique des connaissances à travers la création d'une architecture NIOS. Cette dernière a été utilisée pour coder un chenillard en langage C. Le cahier des charges était simple, consistant à utiliser la plate-forme DE-10 équipée d'un FPGA Max-10 pour développer un chenillard.

# II. Architecture :
À partir du cahier des charges, nous avons déterminé l'architecture à mettre en place sur la plate-forme designer. Le schéma ci-dessous présente notre choix :

![image](https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/98a01b16-ed75-43b0-ab58-5191b9e7ffd8)


Création d'un système NIOS II basique Platform Designer image

Les composants de notre systeme sont:

onchip_memory : Une RAM offrant une capacité de stockage de 40 Mo.

pio_0 : Représente la sortie Qsys de nos 8 leds .

pio_1 : Représente l'entrée Qsys relié à notre bouton poussoir.

pio_2 : Représente les entrées Qsys 4bits relié à nos 4 boutons switch.

![image](https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/c2ae9d63-edcc-4468-be39-abc6bf806272)

# III. Design du code C et VHD :
Nous entrons maintenant dans la partie centrale du TP.

Après la configuration de notre fichier qsys, nous devons créer les codes VHDl de notre système Quartus

![image](https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/678b45e1-2ce1-4080-afc1-1aba3f9b0a9f)

Les différents fichiers du projet sont

lab1.qsys: le fichier qsys généré préalablement dans platform designer

lab1.vhd : Ce fichier définit les entrées et les sorties du système.

![image](https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/e719de61-b7db-4a61-9b45-d34d808818ed)


Flux logiciel du NIOS II Ouvrons un terminal NIOS II et générons le BSP en lien avec les spécifications de la carte DE-10, en ce mettant de préférence dans le répertoire où se trouve nos fichiers vhd et qsys :

![image](https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/1e2b5d4a-5029-4c0c-8975-bf8b7a1be62c)


Pour générer lz fichier BSP, il faut utiliser la commande nio2-bsp hal <system.sopcinfo>

Générons le Makefile du projet avec la commande nios2-app-generate-makefile --app-dir --bsp-dir --elf-name <system.elf> --src-files <fichier.c>

Passons maintenant au code C
Notre code est décomposé comme suit:

Un main où toutes les interruptions vont être activées

![image](https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/7bd27ab9-51b1-4654-a2b1-5d3d425e5d74)

Une fonction chenillard qui va réaliser à travers un while itérant sur le nombre de LEDs, avec un décalage de 1 bit vers la gauche en fonction de la valeur envoyée sur le bus de sortie connecté aux LEDs.

![image](https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/73119e02-1309-4d3a-a546-8fac095e1ed1)

Une fonction se déclenchant lors de l'intéruption du bouton, irqhandler_btn, allumant toutes nos leds en mettant la vitesse de défilement du chenillard à zéro(0).

![image](https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/ac63991b-ea02-48f7-a30c-435588c5d80d)

Et une fonction se déclenchant lors d'une intéruption d'un switch, irqhandler_switch, qui lit la valeur du bus switch et ajuste la vitesse de défilement du chenillard en fonction de cette valeur.

![image](https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/c891a44a-af3c-4056-8679-97f467041af3)

# IV. Résultat :
Voici le résultat obtenu en compilant notre système:

https://github.com/ESN2024/Ndiaye_lab1/assets/153745637/162512c6-8bad-43e6-beb2-2981bf3e883f


# V. Conclusion :
Ce TP a été une introduction fructueuse à l'utilisation d'interruptions, à la conception d'une architecture basée sur NIOS, et à l'implémentation d'un code C sur cette architecture. 
