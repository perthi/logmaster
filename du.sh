#!/bin/bash
# simple perls script to run du and sort the output accoring to size
perl -e'%h=map{/.\s/;99**(ord$&&7)-$`,$_}`du -h`;die@h{sort%h}'
