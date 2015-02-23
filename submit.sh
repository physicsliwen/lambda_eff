#!/bin/bash
if [ -e $GROUP_DIR/group_env.csh ]; then
    source $GROUP_DIR/group_env.csh
fi

cd /global/homes/l/lwen1990/pwg/embedding/Lambda/analysis
root4star -b -q cuts_fp_la.C\(0,700\)
