#!/bin/bash

mpiexec -np $1 -hostfile /home/arm/Source/Sprint3Code/hpl-2.1/arch/armv7l/disney.hosts /home/arm/Source/Sprint3Code/hpl-2.1/arch/armv7l/xhpl
