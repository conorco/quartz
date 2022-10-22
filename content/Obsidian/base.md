---
tags :
author : Conor Cauty
date : <% tp.file.creation_date() %>
title: <%tp.file.title%>
listings-no-page-break: true
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output:
  pdf: 
    pandoc_args: ["--from=markdown+hard_line_breaks"]
    pdf-engine: xelatex
    output: <%tp.file.title%>.pdf
    from: markdown
    listings: true
---