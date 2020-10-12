#!/bin/sh

basename $( find . -type f -name "*.sh" ) | rev | colrm 1 3 | rev
