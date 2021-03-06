This project is out of personal interest and is currently put on hold. The documentation is moving to [GitBook](https://gentlyguitar.gitbooks.io/minispot/content/), this page is
no longer updated. This project is paused because it involves too much details of the VM. I am planning on letting loose of some requirements and not supporting Java thread, and making the implementation easier. 

## Table of Contents
- [Introduction](#introduction)
- [Runtime Overview](#runtime-overview)
- [General Reference](#general-reference)


## Introduction
Aiming to be like [Minix](https://en.wikipedia.org/wiki/MINIX), MiniSpot is an educational JVM based on HotSpot VM. A JVM is not difficult to
understand, this project shows you what a naive JVM really looks like without the high performance tweaks.

It may serve as a teaching assisting tool for compiler classes, or as a guide for students who are interested in high-level language VM implementations.
For example, it provides a clear interface of intermediate representation so that students could use the interface to
practice implementing static analysis and compiler optimizations.

It has the following features compared to the original HotSpot
- Editable with Clion IDE
- Minimized production-style code, much easier to read
- Minimized platform-dependent code by using STL
- Easier to extend, more modular and reusable

For now, MiniSpot only supports linux_x86 platform.

The following section gives an overview of some vital topics.

## Runtime Overview
MiniSpot implements most of HotSpot's runtime services' interface, you may read HotSpot' [runtime overview](http://openjdk.java.net/groups/hotspot/docs/RuntimeOverview.html) first 
to have a general idea. The following overview is MiniSpot specific.
- [VM Creation](doc/creation.md)
- [Bytecode Verification](doc/verification.md)
- [Method Frame](doc/methodframe.md)
- [Java Native Interface](doc/jni.md)

### Heap
`GenCollectedHeap` is defines a generational model for generational GC. Each generation's specific implementation depends on the collector.

Generally a `Generation` derived class should at least implement
- Basic space operations
- Allocation routine
- Collection routine
- Oops iteration

DefNewGeneration is the young gen used by serial GC. It uses this model and implement those operations.

## General Reference
- JVM Specification for Java SE 8
- Java Langugage Specification
- [HotSpot Architecture](http://www.oracle.com/technetwork/java/whitepaper-135217.html#2)
- [CompressedOops](https://wiki.openjdk.java.net/display/HotSpot/CompressedOops)
- [Java HotSpot Virtual Machine Performance Enhancements](http://docs.oracle.com/javase/7/docs/technotes/guides/vm/performance-enhancements-7.html)
- Jikes RVM
- [JavaME CLDC](http://tech-insider.org/mobile/research/acrobat/0502.pdf)
- [JRockit](https://github.com/caoxudong/oracle_jrockit_the_definitive_guide/blob/master/contents.md) (zh-cn)
- Securing Java
