# recls - FAQ <!-- omit in toc -->

The FAQ list is under (constant) development. If you post a question on the
Issues forum (https://github.com/synesissoftware/recls/issues)
it will be used to create one.

- [Q1: "How is this different from ls, which is recursive as well?"](#q1-how-is-this-different-from-ls-which-is-recursive-as-well)
- [Q2: ". "I'm developing an application that needs to run on both WinTEL and Linux, and I'd like to use recls. When will recls support UNIX?"](#q2--im-developing-an-application-that-needs-to-run-on-both-wintel-and-linux-and-id-like-to-use-recls-when-will-recls-support-unix)
- [Q3: "Can anyone contribute to recls?"](#q3-can-anyone-contribute-to-recls)
- [Q4: "When will recls support FTP enumeration?"](#q4-when-will-recls-support-ftp-enumeration)
- [Q5: "Why do you use your own STLSoft libraries? Why not use Boost?"](#q5-why-do-you-use-your-own-stlsoft-libraries-why-not-use-boost)
- [Q6: "Does recls support breadth-first searching (BFS)?"](#q6-does-recls-support-breadth-first-searching-bfs)
- [Q7: "The D standard library docs for recls do not correspond to the version included with the D compiler. What gives?"](#q7-the-d-standard-library-docs-for-recls-do-not-correspond-to-the-version-included-with-the-d-compiler-what-gives)
- [Q8: "Why should I lash out US$40 of my hard-earned cash for your book](#q8-why-should-i-lash-out-us40-of-my-hard-earned-cash-for-your-book)
- [Q9: "Is there a documentation/tutorial besides the API documentation?"](#q9-is-there-a-documentationtutorial-besides-the-api-documentation)
- [Q10: "Is there a newsgroup for recls?"](#q10-is-there-a-newsgroup-for-recls)
- [Q11: "How do I build recls?"](#q11-how-do-i-build-recls)
- [Q12: "Does recls have unit-tests?"](#q12-does-recls-have-unit-tests)


# FAQs: <!-- omit in toc -->

## Q1: "How is this different from ls, which is recursive as well?"

The idea is to have a platform-independent recursive search library, which
can be used in any application, rather than a platform-specific recursive
searching utility, such as ls. By providing mappings to a whole host of
different languages, the kind of code that most people have knocked up for
recursive searching in C or C++ will now be available to developers in
almost any language, and in a well-tested and highly portable form.

## Q2: ". "I'm developing an application that needs to run on both WinTEL and Linux, and I'd like to use recls. When will recls support UNIX?"

Version 1.2.1 (available from 23rd January 2004) supports Linux. Although
it's not been tested on other UNIX flavours it uses no Linux-specific
features, and is very likely to port without any problems to them. All
they need is the readdir(), glob() and stat() APIs

## Q3: "Can anyone contribute to recls?"

Certainly.

## Q4: "When will recls support FTP enumeration?"

As of version 1.5.1 (available from 10th June 2004), recls supports FTP
enumeration for Win32. Support for UNIX will be included in a forthcoming
release.

## Q5: "Why do you use your own STLSoft libraries? Why not use Boost?"

Since I wrote STLSoft, I am very familiar with the facilities the
libraries provide, and am able to best use them. I have also added new
components to STLSoft as a result of the requirements of recls, which I
would not be able to do so easily for another library, such as Boost.

## Q6: "Does recls support breadth-first searching (BFS)?"

Not at the moment. However, after version 1.10.0, I plan to fork the
library and produce recls 2.0, which will introduce substantial changes,
including filtering on size/date/attributes, plug-in pattern matching,
other recursive system searches (such as Win32 registry, CVS, etc.), and
BFS. I expect this will be out sometime mid 2005.

>**NOTE**: [**recls.NET**](http://github.com/synesissoftware/recls.NET) supports both breadth-first and depth-first searching.

## Q7: "The D standard library docs for recls do not correspond to the version included with the D compiler. What gives?"

Since version 1.2.1 of recls, Walter Bright, the creator of D, has not
accepted any updates to recls due to concerns over its code size, both
source and object. Naturally, this has caused consternation for some D
users, who've had to manually compile/build/link std.recls from the
libraries available on this site. Thankfully, version 1.6.1 of recls
includes significant work to refactor the implementation, and trim it
down, and I expect 1.6.1 of recls to feature in the D standard library in
March 2005.

## Q8: "Why should I lash out US$40 of my hard-earned cash for your book
  Imperfect C++? I mean, I know it's currently packing five stars on
  Amazon.com, but what does it give me?"

H.J., that's a great question. All I can say is that if you're a
practising C++ programmer, who is interested in any/all of the issues of
portability, robustness, efficiency or maintainability, then Imperfect C++
is the book for you! And that's my honest, unbiased opinion. :-)

> **NOTE**: This was from around 2005, and much of the material in **Imperfect C++** is now outdated in light of the substantial improvements to C++ over the intervening years.

## Q9: "Is there a documentation/tutorial besides the API documentation?"

Well, yes and no. Almost all of the developments in the core library and
the mappings have been documented in my column Positive Integration in
C/C++ Users Journal (available online at www.ddj.com/columns/wilson). If
you're a subscriber to either CUJ or to DDJ's online resources, then you
can read all about them there.

In addition, there are very plainly written (at least that's the
intention) examples in C and C++, and all of the mapped languages, which
demonstrate most/all the available functionality.

But I'm always painfully aware that my documentation is lacking, so if
there're specific ideas you have for improving it, please let me know, and
I'll be happy to tackle them.

## Q10: "Is there a newsgroup for recls?"

No, but users have tended to post to the STLSoft newsgroups, which is
kindly provided by Digital Mars.

> **NOTE**: It is strongly preferred that you instead use the facilities on the project's GitHub at http://github.com/synesissoftware/recls/.

## Q11: "How do I build recls?"

See instructions in [INSTALL.md](./INSTALL.md).

## Q12: "Does recls have unit-tests?"

Yes, in the **test/unit** and **test/component** directories.


<!-- ########################### end of file ########################### -->

