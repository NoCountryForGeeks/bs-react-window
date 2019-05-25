const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
  entry: './src/Index.bs.js',
  mode: process.env.NODE_ENV,
  output: {
    path: path.join(__dirname, 'build/'),
    filename: `[name].[hash].js`,
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: './index.html',
      hash: true
    })
  ],
  devServer: {
    port: 8080,
    inline: true,
    historyApiFallback: true,
    overlay: {
        errors: true,
        warnings: true
    },
    headers: {
        'Access-Control-Allow-Origin': '*'
    },
    watchOptions: {
        poll: true,
        ignored: [ /node_modules/ ]
    }
  }
};