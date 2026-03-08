# Encoder
Cette librairie permet d'effectuer la mesure d'un capteur de position incrémental à 2 canaux A et B.
Un tel capteur de position fournit 2 signaux digitaux A et B qui peuvent être à l'état haut ou bas
Ces signaux proviennent de 2 sondes placées devant un disque comportant des fentes. Lorsque le disque tourne,
les sondes se retrouvent alternativement devant une fente ou pas, ce qui modifie l'état de sortie.
A chaque transition, on incrémente ou décrémente un compteur.
Les 2 sondes sont décalées l'une par rapport à l'autre de telle sorte que la transition d'une sonde s'effectue toujours 
entre 2 transitions de l'autre sonde, ce qui permet de connaître le sens de rotation et permet de décider si 
on incrémente ou décrémente le compteur.
La librairie est basée sur un système d'Interrupt. L'interrupt est une fonctionnalité qui permet de traiter un bout de code 
en priorité absolue sur le reste du code. Dès que le microcontrôleur détecte un changement d'état de A ou B, la librairie exécute 
l'incrémentation ou décrémentation du compteur, en priorité sur le reste du programme. Cela permet d'éviter de rater une transition
et ainsi s'assurer que le compteur donne une valeur correcte de la position.

This library allows you to measure an incremental position sensor with two channels, A and B.
This type of position sensor provides two digital signals, A and B, which can be either high or low.
These signals come from two probes placed in front of a disc with slots. When the disc rotates,
the probes alternately pass in front of a slot or not, which changes the output state.
At each transition, a counter is incremented or decremented.
The two probes are offset from each other so that the transition of one probe always occurs 
between two transitions of the other probe, which makes it possible to determine the direction of rotation and decide whether 
to increment or decrement the counter.
The library is based on an interrupt system. An interrupt is a feature that allows a piece of code to be processed 
with absolute priority over the rest of the code. As soon as the microcontroller detects a change in the state of A or B, the library executes 
the increment or decrement of the counter, with priority over the rest of the programme. This prevents any transitions from being missed
and ensures that the counter gives a correct position value.