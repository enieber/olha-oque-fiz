/**
 * Bio component that queries for data
 * with Gatsby's useStaticQuery component
 *
 * See: https://www.gatsbyjs.org/docs/use-static-query/
 */
[@bs.module "gatsby"]
external useStaticQuery: string => 'a = "useStaticQuery";
%bs.raw
{| import  {graphql}  from "gatsby" |};

module Image = Gatsby.Image;

[@bs.module "../utils/typography.js"]
external rhythm: float => string = "rhythm";

[@react.component]
let make = () => {
  let data =
    useStaticQuery(
      [%bs.raw
        {|
          graphql`
    query BioQuery {
      avatar: file(absolutePath: { regex: "/profile.jpg/" }) {
        childImageSharp {
          fixed(width: 80, height: 60) {
            ...GatsbyImageSharpFixed
          }
        }
      }
      site {
        siteMetadata {
          author
          social {
            twitter
          }
        }
      }
    }
  `|}
      ],
    );
  let author = data##site##siteMetadata##author;
  let social = data##site##siteMetadata##social;
  <div
    style={
      ReactDOMRe.Style.make(~display="flex", ~marginBottom=rhythm(2.5), ())
    }>
    <Image
      fixed=data##avatar##childImageSharp##fixed
      alt=author
      style={
        ReactDOMRe.Style.make(
          ~marginRight=rhythm(0.5),
          ~marginBottom="0",
          ~minWidth="50",
          ~borderRadius="100%",
          (),
        )
      }
      imgStyle={ReactDOMRe.Style.make(~borderRadius="50%", ())}
    />
    <p>
      {"Escrito por "->React.string}
      <strong> author </strong>
      {", aprendendo Reason ml e Elixir. "->React.string}
      {{j|Veja  algumas coisas que faço no |j}->React.string}
      <a href={"https://enieber.com.br/"}>
        {React.string("meu site")}
      </a>
    </p>
  </div>;
};

React.setDisplayName(make, "Bio");

let default = make;