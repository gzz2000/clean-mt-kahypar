#!/bin/bash

cd boost
rsync -a --remove-source-files ../libs/*/include/boost/* .
cd ..
mv boost boost_kahypar
sed -i'' -E "s/<boost\//<boost_kahypar\//g" $(grep -l -Inr "<boost_kahypar/" .)
sed -i'' -E 's/"boost\//"boost_kahypar\//g' $(grep -l -Inr '"boost_kahypar/' .)
sed -i'' -E 's/BOOST_PP_STRINGIZE\(boost\//BOOST_PP_STRINGIZE\(boost_kahypar\//g' $(grep -l -Inr 'BOOST_PP_STRINGIZE(boost_kahypar/' .)
