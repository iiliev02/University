<xsl:transform version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>

    <xsl:template match="/">
        <accesses version="1.0">
            <xsl:apply-templates select="/cinema/movies"/>
        </accesses>
    </xsl:template>

    <xsl:template match="/cinema/movies">
        <xsl:for-each select = "movie[@genre='Фантастика']">
            <movie>
                <name>
                    <xsl:value-of select="movieName"/>
                </name>
                <genre>
                    <xsl:value-of select="@genre"/>
                </genre>
                <duration>
                    <xsl:value-of select="duration"/>
                </duration>
                <projections>
                    <xsl:value-of select="projections"/>
                </projections>
            </movie>
        </xsl:for-each>
    </xsl:template>

</xsl:transform>