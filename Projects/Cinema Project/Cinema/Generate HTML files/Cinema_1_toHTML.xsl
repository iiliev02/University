<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html"/>

    <xsl:template match="/">
        <html lang="bg">
            <head>
                <meta charset="UTF-8"/>
                <title>Contacts</title>
                <link rel="stylesheet" href="styleGenedHTMl.css"></link>
            </head>
            <body>
                <xsl:apply-templates select="/cinema/contacts"/>
            </body>
        </html>
    </xsl:template>

    <xsl:template match="/cinema/contacts">
        <div class="container">
            <h2>Contacts Cinema</h2>
            <ul>
                <li class="table-header">
                    <div class="col col-1">Country</div>
                    <div class="col col-2">City</div>
                    <div class="col col-3">Street</div>
                    <div class="col col-4">Email</div>
                    <div class="col col-5">Phone</div>
                </li>
                <li class="table-row">
                    <div class="col col-1" data-label="Country"><xsl:value-of select="country"/></div>
                    <div class="col col-2" data-label="City"><xsl:value-of select="city"/></div>
                    <div class="col col-3" data-label="Street"><xsl:value-of select="street"/></div>
                    <div class="col col-4" data-label="Email"><xsl:value-of select="email"/></div>
                    <div class="col col-5" data-label="Phone"><xsl:value-of select="phone"/></div>
                </li>
            </ul>
        </div>
    </xsl:template>

</xsl:transform>