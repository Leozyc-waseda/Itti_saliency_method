#!/usr/bin/python

from threading import Thread
import os
import pexpect

nodelist = ['bx1','bx2','bx3','bx4','bx5','bx6','bx7','bx8'] 
nodeDHCP = range(29)

#DHCP 120 to 149

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'

    def disable(self):
        self.HEADER = ''
        self.OKBLUE = ''
        self.OKGREEN = ''
        self.WARNING = ''
        self.FAIL = ''
        self.ENDC = ''

class pingWorker(Thread):
  up = False
  nodeName = ''
  def __init__(self, nodeName):
    Thread.__init__(self)
    self.nodeName = '192.168.0.'+str(nodeName+120)

  def run(self):
    res = pexpect.run('ping -q -c2 '+self.nodeName, timeout=2)
    res = res.split('\n')
    
    if(len(res) > 2):
      packetLoss = int(res[-3].split(',')[2].split('%')[0].strip())
      if(packetLoss == 0):
        self.up = True
      else:
        self.up = False
    else:
      self.up = False

pingList = []
for node in nodeDHCP:
  pingList.append(pingWorker(node))
  print 'ping'+str(node)
  pingList[-1].start()

for node in pingList:
  node.join()

  color = bcolors.FAIL
  status = 'DOWN'
  if(node.up == True):
    color = bcolors.OKGREEN
    status = 'UP'

  print node.nodeName + ' : ' + color + status + bcolors.ENDC

