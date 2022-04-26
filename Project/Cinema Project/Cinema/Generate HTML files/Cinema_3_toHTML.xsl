<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html"/>

    <xsl:template match="/">
        <html lang="bg">
            <head>
                <meta charset="UTF-8"/>
                <title>Movies</title>
                <link rel="stylesheet" href="styleGenedHTMl.css"></link>
                <style>
                    .col-1{
                    flex-basis: 45%;
                    }
                </style>
            </head>
            <body>
                <xsl:apply-templates select="/cinema/movies"/>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="/cinema/movies">
        <div class="container">
            <h2>Movies</h2>
            <ul>
                <li class="table-header">
                    <div class="col col-1">Name</div>
                    <div class="col col-2">Category</div>
                    <div class="col col-3">Projections</div>
                    <div class="col col-4">Duration</div>
                    <div class="col col-5">Ticket</div>
                </li>
                <xsl:for-each select = "movie">
                    <xsl:sort select = "substring(duration, 1, 3)" data-type="number" order="ascending"/>
                    <li class="table-row">
                        <div class="col col-1" data-label="Name"><xsl:value-of select="movieName"/></div>
                        <div class="col col-2" data-label="Category"><xsl:value-of select="@category"/></div>
                        <div class="col col-3" data-label="Duration"><xsl:value-of select="duration"/></div>
                        <div class="col col-4" data-label="Projection"><xsl:value-of select="projections"/></div>
                        <div class="col col-5" data-label="Ticket"><xsl:value-of select="ticket"/>&#160;<xsl:value-of select="ticket/@currency"/></div>
                    </li>
                </xsl:for-each>
            </ul>
        </div>
    </xsl:template>

</xsl:transform>