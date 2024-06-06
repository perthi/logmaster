#!/bin/bash
make distclean
pushd submodules/productivity/
make distclean
popd
pushd submodules/xml-parser
make distclean
popd
